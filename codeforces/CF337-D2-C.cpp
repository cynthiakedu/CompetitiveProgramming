#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000009
ll N, M, K;

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    ll amt = max(0LL, M - (N - M + 1) * (K - 1));

    ll x = (amt + K - 1) / K;
    ll y = M - x * K;

    ll ans = (powmod(2, x + 1) - 2 + MOD) % MOD;
    ans = (ans * K) % MOD;
    ans = (ans + y) % MOD;
    cout << ans << endl;

    return 0;
}
