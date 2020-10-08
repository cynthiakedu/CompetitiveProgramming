#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
double arr[100][100];
double dp[10][100][100];
double prob[10][100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= (1 << N); i++) {
        for (int j = 1; j <= (1 << N); j++) {
            cin >> arr[i][j];
            arr[i][j] /= 100.0;
        }
    }

    for (int i = 0; i <= N; i++) {
        for (int j = (1 << N); j >= 1; j -= (1 << i)) {
            for (int k = 1; k <= (1 << N); k++) {
                if (i == 0) {
                    prob[i][j][k] = (k == j ? 1.0 : 0.0);
                    continue;
                }
                int j1 = j - (1 << (i - 1));
                for (int k1 = 1; k1 <= (1 << N); k1++) {
                    if (k1 == k) continue;
                    prob[i][j][k] += prob[i - 1][j1][k1] * prob[i - 1][j][k] * arr[k][k1];
                    prob[i][j][k] += prob[i - 1][j1][k] * prob[i - 1][j][k1] * arr[k][k1];
                }

                for (int k1 = 1; k1 <= (1 << N); k1++) {
                    if (k1 == k) continue;
                    double x = dp[i - 1][j1][k1] + dp[i - 1][j][k] + prob[i][j][k] * (1 << (i - 1));
                    double y = dp[i - 1][j1][k] + dp[i - 1][j][k1] + prob[i][j][k] * (1 << (i - 1));
                    dp[i][j][k] = max(dp[i][j][k], max(x, y));
                }
            }
        }
    }
    double ans = 0;
    for (int i = 1; i <= (1 << N); i++) {
        ans = max(ans, dp[N][(1 << N)][i]);
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
