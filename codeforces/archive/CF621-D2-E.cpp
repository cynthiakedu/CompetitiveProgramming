#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 100005
#define MOD 1000000007
bool debug = true;

int N, B, K, X;
ll dp[30][105];

ll powmod(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2, mod);
    return (((z * z) % mod) * (b % 2 ? a : 1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> B >> K >> X;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        dp[0][x % X]++;
    }

    for (int i = 1; i < 30; i++) {
        ll t = powmod(10, (1 << (i - 1)), X);
        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                ll newmod = ((j * t) % X + k) % X;
                dp[i][newmod] = (dp[i][newmod] + (dp[i - 1][j] * dp[i - 1][k]) % MOD) % MOD;
            }
        }
    }

    ll ans[105] = {};
    ans[0] = 1;
    ll curr = 0;  //initially put this inside the loop

    for (int i = 0; i < 30; i++) {
        ll temp[105] = {};
        if (B & (1 << (i))) {
            ll t = powmod(10, curr, X);

            for (int j = 0; j < X; j++) {
                for (int k = 0; k < X; k++) {
                    ll newmod = ((j * t) % X + k) % X;
                    temp[newmod] = (temp[newmod] + (dp[i][j] * ans[k]) % MOD) % MOD;
                }
            }
            for (int i = 0; i < 105; i++) ans[i] = temp[i];
            curr += (1 << i);
        }
    }
    cout << ans[K] << "\n";
    return 0;
}
