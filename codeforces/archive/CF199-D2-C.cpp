#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll K, N, B, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> B >> N >> T;

    if (K == 1) {
        if (T >= 1 + B * N) {
            cout << 0 << endl;
            return 0;
        }
        ll a = 1 + N * B - T;
        cout << (ll)(a + B - 1) / B << endl;
    } else {
        double x = 1 + 1.0 * B / (K - 1);
        double z = 1.0 * T / x;
        if (log(z) / log(K) >= 1.0 * N) {
            cout << 0 << endl;
            return 0;
        }
        x = 1 + 1.0 * B / (K - 1);
        double y = T + 1.0 * B / (K - 1);
        cout << (ll)ceil(N + log(x / y) / log(K)) << endl;
    }

    return 0;
}
