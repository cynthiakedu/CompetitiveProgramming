#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int v1, v2, t, d;
int dp[120][120];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> v1 >> v2 >> t >> d;
    dp[t][v2] = v2;
    for (int i = t - 1; i >= 1; i--) {
        for (int j = 0; j <= 110; j++) {
            for (int k = 0; k <= 110; k++) {
                if (abs(k - j) <= d && dp[i + 1][k] != -1) {
                    dp[i][j] = max(dp[i][j], j + dp[i + 1][k]);
                }
            }
        }
    }
    cout << dp[1][v1] << endl;

    return 0;
}
