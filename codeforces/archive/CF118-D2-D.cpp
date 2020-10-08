#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 100000000
ll N1, N2, K1, K2;
ll K[2];
ll dp[105][105][15][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N1 >> N2 >> K[0] >> K[1];
    for (int i = 0; i <= N1; i++) {
        for (int j = 0; j <= N2; j++) {
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b <= K[a]; b++) {
                    ll& ret = dp[i][j][b][a];
                    if (i == 0 && j == 0) {
                        ret = 1;
                        continue;
                    }
                    if (a == 0) {
                        if (b < K[0] && i > 0) {
                            ret = (ret + dp[i - 1][j][b + 1][a]) % MOD;
                        }
                        if (j > 0) {
                            ret = (ret + dp[i][j - 1][1][1 - a]) % MOD;
                        }
                    }
                    if (a == 1) {
                        if (b < K[1] && j > 0) {
                            ret = (ret + dp[i][j - 1][b + 1][a]) % MOD;
                        }
                        if (i > 0) {
                            ret = (ret + dp[i - 1][j][1][1 - a]) % MOD;
                        }
                    }
                }
            }
        }
    }
    cout << dp[N1][N2][0][0] << endl;

    return 0;
}
