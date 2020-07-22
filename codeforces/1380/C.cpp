#include <bits/stdc++.h>
using namespace std;
int T, N, X;

void solve() {
  int arr[100005] = {}, dp[100005] = {};
  cin >> N >> X;
  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  sort(arr + 1, arr + N + 1);
  for (int i = N; i >= 1; i--) {
    dp[i] = dp[i + 1];
    int num = ((X + arr[i] - 1) / arr[i]);
    if (N - i + 1 >= num) {
      dp[i] = max(dp[i], 1 + dp[i + num]);
    }
  }
  cout << dp[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }

  return 0;
}
