#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, K, M, D;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> M >> D;

    for (ll i = 1; i <= D; i++) {
        ll a = (i == 1 ? M : (N - 1) / (K * (i - 1)));
        ll x = min(M, a);
        if (x == 0) continue;
        if (i == 1) {
            cout << "hey " << (N / x + K - 1) / (K) << endl;
        } else {
            ans = max(ans, x * i);
        }
        if (i == 3) {
            cout << "i 3 " << x << endl;
            if (x * (K * D + 1) >= N + 1) cout << "YAY" << endl;
        }
        // if (x != M) {
        //     cout << "I " << i << " " << x << endl;
        // }
        if (x * i == 8325624421831635) cout << "ha" << endl;

        // if (x * (K * D + 1) >= N + 1) cout << "YAY" << endl;
        // if ((N / x + K - 1) / (K) != i) cout << "oops " << i << endl;
        // if ( != D) continue;
    }
    cout << ans << endl;

    return 0;
}
