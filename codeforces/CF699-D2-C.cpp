#include <bits/stdc++.h>
using namespace std;
int N, arr[105];
int dp[105][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = N + 1; i >= 1; i--) {
        if (i == N + 1) {
            for (int j = 0; j < 3; j++) dp[i][j] = 0;
            continue;
        }
        for (int j = 0; j < 3; j++) dp[i][j] = 1 + dp[i + 1][0];

        if (arr[i] == 1 || arr[i] == 3) {  //can C
            dp[i][0] = min(dp[i][0], dp[i + 1][2]);
            dp[i][1] = min(dp[i][1], dp[i + 1][2]);
        }
        if (arr[i] == 2 || arr[i] == 3) {  //can G
            dp[i][0] = min(dp[i][0], dp[i + 1][1]);
            dp[i][2] = min(dp[i][2], dp[i + 1][1]);
        }
        // cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << dp[1][0] << endl;
    return 0;
}
