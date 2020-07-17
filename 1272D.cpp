#include <bits/stdc++.h>
using namespace std;
int N, arr[200005], dp[2][200005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) {
    dp[0][i] = 1;
    dp[1][i] = 1;

    if (i > 1 && arr[i] > arr[i - 1]) {
      dp[0][i] = max(dp[0][i], 1 + dp[0][i - 1]);
      dp[1][i] = max(dp[1][i], 1 + dp[1][i - 1]);
    }
    if (i > 2 && arr[i] > arr[i - 2]) {
      dp[0][i] = max(dp[0][i], 1 + dp[1][i - 2]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 2; j++) {
      ans = max(ans, dp[j][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
