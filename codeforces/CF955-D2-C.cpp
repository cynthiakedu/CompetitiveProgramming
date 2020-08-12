#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int Q;
ll L, R;

ll p(ll a, ll b) {
    if (b == 0) return 1;
    ll z = p(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        int arr[130] = {};
        ll ans = 0;

        for (ll i = 2; i <= 128; i++) {
            ll a = ceil(pow((double)L, 1.0 / i));
            ll b = floor(pow((double)R, 1.0 / i));
            if (b >= a && b > 1) {
                arr[i] = b - a + 1;
            }
            // cout << "arr[i] " << i << " " << arr[i] << endl;
        }
        ans = arr[2];
        ll g = 2;
        for (ll j = 3; j <= 64; j++) {
            ans += arr[j];
            // for (ll k = 64)
            if (j <= 32) {
                g = g * (j / gcd(g, j));
            } else {
            }
            // g =
            cout << "g " << g << endl;
            if (g <= 128) {
                ans -= arr[g];
            }
        }

        cout << ans << endl;
    }

    return 0;
}
