#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int N, K;

ll binom[2505][2505];

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

ll ct(ll k1) {
    ll amt = (((binom[K][k1] * k1) % MOD) * powmod(k1 - 1, N - 1)) % MOD;
    if ((K - k1) % 2 == 1) amt *= -1;
    return (amt + 2 * MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0, u; i < N - 1; i++) {
        cin >> u;
    }

    for (int n = 1; n < 2505; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 || k == n) {
                binom[n][k] = 1;
            } else {
                binom[n][k] = (binom[n - 1][k] + binom[n - 1][k - 1]) % MOD;
            }
        }
    }

    ll ans = 0;

    for (ll i = K; i >= 1; i--) {
        ll x = ct(i);
        ans = (ans + ct(i)) % MOD;
    }
    cout << ans << endl;

    return 0;
}
