#include <iomanip>
#include <iostream>
using namespace std;
#define ll long long
#define ii pair<int, int>
int M, T, N;
double arr[1005][35];
double dp[1005][35][35];
double ans1[1005][35];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> M >> T >> N;
        if (!M && !T && !N) return 0;
        for (int i = 1; i <= T; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 1; i <= T; i++) {
            for (int j = 0; j <= M; j++) {
                for (int k = 0; k <= M; k++) {
                    if (j == 0) {
                        dp[i][j][k] = (k == 0 ? 1.0 : 0.0);
                        continue;
                    }
                    dp[i][j][k] = (1.0 - arr[i][j]) * dp[i][j - 1][k];
                    if (k >= 1) {
                        dp[i][j][k] += arr[i][j] * dp[i][j - 1][k - 1];
                    }
                }
            }
            for (int j = 0; j <= M; j++) {
                ans1[i][j] = dp[i][M][j];
                if (j > 0) {
                    ans1[i][j] += ans1[i][j - 1];
                }
            }
        }
        double prob1 = 1.0, prob2 = 1.0;
        for (int i = 1; i <= T; i++) {
            prob1 *= 1.0 - ans1[i][0];
            prob2 *= ans1[i][N - 1] - ans1[i][0];
        }
        cout << fixed << setprecision(3) << prob1 - prob2 << endl;
    }

    return 0;
}
