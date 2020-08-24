#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
ll A, arr1[100005], arr2[100005];

bool can(int x) {
    ll amt = 0;
    for (int i = 1; i <= x; i++) {
        ll a = arr1[i], b = arr2[N - x + i];
        if (a > b) amt += a - b;
    }
    return amt <= A;
}

ll ct(int x) {
    ll s = 0;
    for (int i = 1; i <= x; i++) {
        s += arr1[i];
    }
    return max(s - A, 0LL);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> A;
    for (int i = 1; i <= N; i++) cin >> arr2[i];
    for (int i = 1; i <= M; i++) cin >> arr1[i];
    sort(arr2 + 1, arr2 + N + 1);
    sort(arr1 + 1, arr1 + M + 1);

    int l = 0, r = min(N, M);
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (can(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    if (l == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    cout << l << " " << ct(l) << endl;

    return 0;
}
