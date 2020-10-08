#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

ll lcm(ll x, ll y) {
    ll g = gcd(x, y);
    return x * y / g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    ll mx = 1;
    ll low = max(1LL, N - 8);
    for (ll i = low; i <= N; i++) {
        for (ll j = low; j <= N; j++) {
            for (ll k = low; k <= N; k++) {
                ll ret = lcm(lcm(i, j), k);
                mx = max(mx, ret);
            }
        }
    }
    cout << mx << endl;

    return 0;
}
