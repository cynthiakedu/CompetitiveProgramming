#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll T, N, K, a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        cin >> a >> b >> c >> d;
        if (c <= a) {
            swap(a, c);
            swap(b, d);
        }
        ll already = N * max(0LL, min(b, d) - c);
        if (K <= already) {
            cout << 0 << endl;
            continue;
        }
        K -= already;

        ll x = max(c - b, 0LL), y = (b >= d ? b - d : d - max(b, c)) + c - a;

        if (K <= y) {
            cout << x + K << endl;
            continue;
        }

        if (y <= x) {
            cout << x + y + (K - y) * 2 << endl;
            continue;
        }
        ll ans = 0;
        ll num = min(K / y, N);
        ans += num * (x + y);
        K -= num * y;
        if (K >= x && num < N) {
            ans += x + K;
        } else {
            ans += 2 * K;
        }
        cout << ans << endl;
    }
    return 0;
}

// 2
// 3 3
// 1 5
// 3 4
// 3 11
// 1 2
// 3 4