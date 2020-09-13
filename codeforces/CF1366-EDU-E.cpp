#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 998244353
const int mxN = 2e5;
int N, M, a[mxN + 5], b[mxN + 5], fst[mxN + 5];
map<int, int> m;
ll ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        m[a[i]] = i;
    }
    for (int i = 1; i <= M; i++) cin >> b[i];

    for (int i = 1; i <= M; i++) {
        if (m.count(b[i]) == 0) {
            cout << 0 << endl;
            return 0;
        }
        fst[i] = m[b[i]];
    }
    for (int i = 1; i < M; i++) {
        if (fst[i] > fst[i + 1]) {
            cout << 0 << endl;
            return 0;
        }
    }
    a[0] = INT_MAX;
    a[N + 1] = INT_MAX;
    fst[0] = 0;
    fst[M + 1] = N + 1;
    for (int i = 0; i <= M; i++) {
        int x = fst[i], y = fst[i + 1];
        int c = a[x], d = a[y];
        for (int j = x + 1; j < y; j++) {
            if (a[j] < c && a[j] < d) {
                cout << 0 << endl;
                return 0;
            }
        }
        if (x == 0) continue;
        int idx = x;
        for (int j = x; j < y; j++) {
            if (a[j] < d) {
                idx = j;
            }
        }
        ans = (ans * (ll)(y - idx)) % MOD;
    }
    cout << ans % MOD << endl;

    return 0;
}
