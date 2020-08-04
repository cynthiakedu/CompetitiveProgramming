#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
ll M, D, W;

int gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

ll calc(ll n, ll s) {
    ll ret = ((n / s) * (n / s - 1) / 2) * s;
    ret += (n % s + 1) * (n / s);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> D >> W;
        ll need = W / gcd(W, D - 1);
        ll ans = calc(min(M, D) - 1, need);
        cout << ans << endl;
    }

    return 0;
}
