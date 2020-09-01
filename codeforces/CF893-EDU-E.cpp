#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 1e6;
int T;
ll x, y;

vector<ll> dp[mxN + 5];
ll fact[2 * mxN + 5];

vector<ll> primes;
bool vis[mxN + 5];

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

vector<ll> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < mxN + 5; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < mxN + 5; j += i) {
            dp[j].push_back(i);
            vis[j] = true;
        }
    }
    fact[0] = 1;
    for (ll i = 1; i < 2 * mxN + 5; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> x >> y;
        ll x1 = x;
        ll ans = 1;
        for (ll p : dp[x1]) {
            ll ct = 0;
            while (x1 % p == 0) {
                x1 /= p;
                ct++;
            }
            ll temp = ((fact[ct + y - 1] * inv(fact[y - 1], MOD)) % MOD * inv(fact[ct], MOD)) % MOD;
            ans = (ans * temp) % MOD;
        }
        ans = (ans * powmod(2, y - 1)) % MOD;
        cout << ans << endl;
    }

    return 0;
}
