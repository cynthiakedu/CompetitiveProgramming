#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 998244353
int N, K;
ll dp[505][505], cum[505][505], dp2[505];
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int j = 1; j <= N; j++) {
        cum[j][N + 1] = 1;
        for (int i = N; i >= 1; i--) {
            int r = min(N, i + j - 1);
            ll temp = (cum[j][i + 1] - cum[j][r + 2] + MOD) % MOD;
            dp[j][i] = (dp[j][i] + temp) % MOD;
            cum[j][i] = (dp[j][i] + cum[j][i + 1]) % MOD;
        }
    }
    for (int i = 1; i <= N; i++) {
        dp2[i] = (dp[i][1] - dp[i - 1][1] + 2 * MOD) % MOD;
    }

    for (int i = 1; i <= min(N, K); i++) {
        int j = min((K - 1) / i, N);
        ll temp = ((2 * dp2[i]) % MOD * dp[j][1]) % MOD;
        ans = (ans + temp) % MOD;
    }
    cout << ans << endl;

    return 0;
}
