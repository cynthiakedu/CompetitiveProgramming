#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, T;
double p;
double dp[55][30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(dp, 0, sizeof dp);
        cin >> N;
        cin >> p;

        for (int i = 1; i <= 2 * N - 1; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 1) {
                    dp[i][j] = j == 1 ? p : j == 0 ? 1 - p : 0;
                    continue;
                }
                if (j == 0) {
                    dp[i][0] = (1 - p) * dp[i - 1][0];
                    continue;
                }

                dp[i][j] = p * dp[i - 1][j - 1] + (j < N ? (1 - p) * dp[i - 1][j] : 0);
            }
        }
        double ans = 0;
        for (int i = 1; i <= 2 * N - 1; i++) {
            ans += dp[i][N];
        }
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
