#include <bits/stdc++.h>
using namespace std;
int N, M, X, Y;
char arr[1005][1005] = {};
int amt[1005] = {};
long long dp[1005][1005][2] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X >> Y;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '#') amt[j]++;
        }
    }
    for (int i = M + 1; i >= 2; i--) {
        for (int j = Y; j >= 0; j--) {
            if (i == M + 1) {
                dp[i][j][1] = j >= X ? 0 : INT_MAX;
                dp[i][j][0] = j >= X ? 0 : INT_MAX;
                continue;
            }
            dp[i][j][0] = INT_MAX;  //prev col #
            dp[i][j][1] = INT_MAX;  //prev col .
            if (X <= j && j <= Y) {
                dp[i][j][0] = min(dp[i][j][0], amt[i] + dp[i + 1][1][1]);
                dp[i][j][1] = min(dp[i][j][1], N - amt[i] + dp[i + 1][1][0]);
            }
            if (j < Y) {
                dp[i][j][0] = min(dp[i][j][0], N - amt[i] + dp[i + 1][j + 1][0]);
                dp[i][j][1] = min(dp[i][j][1], amt[i] + dp[i + 1][j + 1][1]);
            }
        }
    }
    cout << min(N - amt[1] + dp[2][1][0], amt[1] + dp[2][1][1]) << endl;

    return 0;
}
