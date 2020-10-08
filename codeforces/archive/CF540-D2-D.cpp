#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
double dp[105][105][105][3];
int arr[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> arr[0] >> arr[1] >> arr[2];

    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            for (int k = 0; k < 105; k++) {
                for (int s = 0; s < 3; s++) {
                    vector<int> v = {i, j, k};
                    int sum = i + j + k;
                    if (!i && !j) {
                        dp[i][j][k][s] = s == 2 ? 1.0 : 0.0;
                        continue;
                    }
                    if (!i && !k) {
                        dp[i][j][k][s] = s == 1 ? 1.0 : 0.0;
                        continue;
                    }
                    if (!j && !k) {
                        dp[i][j][k][s] = s == 0 ? 1.0 : 0.0;
                        continue;
                    }

                    double s2 = 0, p1 = 0, p2 = 0, p3 = 0;
                    double& x = dp[i][j][k][s];

                    if (i >= 1 && j >= 1) {
                        p1 = (1.0 * i * j / (sum * (sum - 1) / 2));
                        s2 += p1;
                        dp[i][j][k][s] += p1 * dp[i][j - 1][k][s];
                    }

                    if (i >= 1 && k >= 1) {
                        p2 = (1.0 * i * k / (sum * (sum - 1) / 2));
                        dp[i][j][k][s] += p2 * dp[i - 1][j][k][s];
                    }

                    if (j >= 1 && k >= 1) {
                        p3 = (1.0 * j * k / (sum * (sum - 1) / 2));
                        dp[i][j][k][s] += p3 * dp[i][j][k - 1][s];
                    }

                    dp[i][j][k][s] /= (p1 + p2 + p3);
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << setprecision(16) << dp[arr[0]][arr[1]][arr[2]][i] << (i == 2 ? "\n" : " ");
    }

    return 0;
}