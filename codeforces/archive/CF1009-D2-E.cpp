#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 998244353
const int mxN = 1e6;
ll N, arr[mxN + 5];

ll ans;

ll powmod(ll a, ll b) {
    if (b <= 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (ll i = 1; i <= N; i++) {
        ll tmp = (powmod(2, N - i) + ((N - i) * powmod(2, N - i - 1)) % MOD) % MOD;
        ans = (ans + (tmp * arr[i]) % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}
