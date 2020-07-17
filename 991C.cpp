#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, N2;
ll ans;

ll calc(ll x)
{
    ll ret = 0, t = N;
    if (x == 0)
        return 0;
    while (t > 0) {
        ll amt = min(t, x);
        t -= amt;
        ret += amt;
        t -= t / 10;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    N2 = (N + 1) / 2;
    ans = N2;

    for (ll k = 0; k < min(N2 + 1, (ll)10); k++) {
        ll l = 0, r = (N - k) / 10;
        while (l < r) {
            ll m = (l + r) / 2;
            ll res = calc(k + 10 * m);
            if (res >= N2) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (calc(k + 10 * l) >= N2) {
            ans = min(ans, k + 10 * l);
        }
    }
    cout << ans << endl;

    return 0;
}
