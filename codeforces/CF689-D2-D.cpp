#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 200005
bool debug = false;

int N, arr1[MXN], arr2[MXN], mn[18][MXN], mx[18][MXN];
ll ans = 0;

bool check(int l, int r, bool tf) {
    int k = (int)log2(r - l + 1);
    int a = min(mn[k][l], mn[k][r - (1 << k) + 1]);
    int b = max(mx[k][l], mx[k][r - (1 << k) + 1]);
    if (tf)
        return b < a;
    else
        return b > a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr1[i];
    for (int i = 1; i <= N; i++) cin >> arr2[i];

    for (int i = 0; i < 18; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 0) {
                mx[i][j] = arr1[j], mn[i][j] = arr2[j];
            } else {
                int r = j + (1 << i) - 1;
                if (r > N) continue;
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][r - (1 << (i - 1)) + 1]);
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][r - (1 << (i - 1)) + 1]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int l1 = i, r1 = N;
        while (l1 < r1) {
            int m = (l1 + r1 + 1) / 2;
            bool ok = check(i, m, true);
            if (debug) cout << "bs1 " << i << " " << m << " " << ok << endl;
            if (ok) {
                l1 = m;
            } else {
                r1 = m - 1;
            }
        }
        if (!check(i, l1, true)) l1 = i - 1;

        int l2 = i, r2 = N;
        while (l2 < r2) {
            int m = (l2 + r2) / 2;
            bool ok = check(i, m, false);
            if (debug) cout << "bs1 " << i << " " << m << " " << ok << endl;
            if (check(i, m, false)) {
                r2 = m;
            } else {
                l2 = m + 1;
            }
        }
        if (!check(i, l2, false)) l2 = N + 1;
        if (debug) cout << "res " << i << " " << l1 << " " << l2 << endl;
        ans += l2 - l1 - 1;
    }
    cout << ans << "\n";

    return 0;
}
