#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string arr[20];
double prob[20][20];
double dp[10][20][20];

int pow(int a, int b) {
    if (b == 0) return 1;
    int z = pow(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 16; i++) cin >> arr[i];
    for (int i = 1; i <= 16; i++) {
        for (int j = 1; j <= 16; j++) {
            cin >> prob[i][j];
            prob[i][j] /= 100;
        }
    }

    for (int i = 0; i <= 4; i++) {
        for (int j = pow(2, i); j <= 16; j += pow(2, i)) {
            for (int k = 1; k <= 16; k++) {
                if (i == 0) {
                    dp[i][j][k] = (j == k);
                    continue;
                }
                int a = j - pow(2, i - 1), b = j;
                double& res = dp[i][j][k];
                for (int l = 1; l <= 16; l++) {
                    res += dp[i - 1][a][k] * dp[i - 1][b][l] * prob[k][l];
                    res += dp[i - 1][a][l] * dp[i - 1][b][k] * prob[k][l];
                }
                // cout << "i j k " << i << " " << j << " " << k << res << endl;
            }
        }
    }
    for (int i = 1; i <= 16; i++) {
        cout << right << setw(10) << arr[i] << " "
             << "p=" << fixed << setprecision(2) << dp[4][16][i] * 100 << "%" << endl;
    }

    return 0;
}
