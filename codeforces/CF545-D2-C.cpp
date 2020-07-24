#include <bits/stdc++.h>
using namespace std;
int N, arr[100005][2], dp[100005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = N + 1; i >= 2; i--) {
        if (i == N + 1) {
            dp[i][0] = 0;
            dp[i][1] = 0;
            continue;
        }
        dp[i][0] = dp[i + 1][0];
        dp[i][1] = dp[i + 1][0];

        if (arr[i][0] - arr[i][1] > arr[i - 1][0]) {
            dp[i][0] = max(dp[i][0], 1 + dp[i + 1][0]);
        }
        if (arr[i][0] - arr[i][1] > arr[i - 1][0] + arr[i - 1][1]) {
            dp[i][1] = max(dp[i][1], 1 + dp[i + 1][0]);
        }
        if (arr[i][0] + arr[i][1] < arr[i + 1][0] || i == N) {
            dp[i][0] = max(dp[i][0], 1 + dp[i + 1][1]);
            dp[i][1] = max(dp[i][1], 1 + dp[i + 1][1]);
        }
    }

    cout << 1 + dp[2][0] << endl;

    return 0;
}
