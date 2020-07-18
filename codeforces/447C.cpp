#include <bits/stdc++.h>
using namespace std;
int N, arr[100005], dp[100005][2];
int ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  for (int i = 1; i <= N; i++) {
    dp[i][0] = 1;
    dp[i][1] = 2;
    if (i >= 2 && arr[i] > arr[i - 1]) {
      dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
    }
    if (i >= 3) {
      if (arr[i] > arr[i - 1]) {
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
      }
      if (arr[i] > arr[i - 2]) {
        dp[i][1] = max(dp[i][1], dp[i - 2][0] + 2);
      }
    }
    ans = max(ans, dp[i][0]);
    ans = max(ans, dp[i][1]);
  }
  cout << ans << endl;

  return 0;
}
