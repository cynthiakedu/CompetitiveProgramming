#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K, D;
ll dp[105][2];
ll MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K >> D;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < 2; j++) {
      if (i == 0) {
        dp[i][j] = j;
        continue;
      }
      for (int k = 1; k <= K; k++) {
        if (i >= k) {
          dp[i][j] = (dp[i][j] + dp[i - k][j || (k >= D)]) % MOD;
        }
      }
    }
  }
  cout << dp[N][0] << endl;
  return 0;
}
