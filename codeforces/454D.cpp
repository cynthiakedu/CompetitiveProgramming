// Followed tutorial
#include <bits/stdc++.h>
using namespace std;
int N, arr[105], K[105];
int dp[105][1 << 17], ans[105][1 << 17];
bool vis[105];
vector<int> primes;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i <= 60; i++) {
    if (!vis[i]) {
      primes.push_back(i);
      for (int j = i; j <= 60; j += i) {
        vis[j] = true;
      }
    }
  }

  for (int i = 2; i <= 60; i++) {
    for (int j = 0; j < primes.size(); j++) {
      if (i % primes[j] == 0) {
        K[i] = K[i] | (1 << j);
      }
    }
  }
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < (1 << 17); j++) {
      dp[i][j] = i == 0 ? 0 : INT_MAX;
    }
  }

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  for (int i = 1; i <= N; i++) {
    for (int k = 1; k < 60; k++) {
      int x = (~K[k]) & ((1 << 17) - 1);
      for (int s = x;; s = (s - 1) & x) {
        if (dp[i - 1][s] + abs(arr[i] - k) < dp[i][s | K[k]]) {
          dp[i][s | K[k]] = dp[i - 1][s] + abs(arr[i] - k);
          ans[i][s | K[k]] = k;
        }
        if (s == 0) break;
      }
    }
  }
  // cout << dp[1][0];
  vector<int> ansV;
  int x;
  int a = INT_MAX;
  int s;
  for (int i = 0; i < (1 << 17); i++) {
    if (dp[N][i] < a) {
      x = ans[N][i];
      a = dp[N][i];
      s = i;
    }
  }
  // cout<<"s "<<s<<endl;
  ansV.push_back(x);
  for (int i = N - 1; i >= 1; i--) {
    s = s - K[x];
    x = ans[i][s];
    ansV.push_back(x);
  }

  reverse(ansV.begin(), ansV.end());
  for (int i = 0; i < N; i++) cout << ansV[i] << (i == (N - 1) ? "\n" : " ");

  return 0;
}
