#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
int N, K, b[2005];
vector<int> adjList[2005];
ll memo[2005][2005], ans = 0;

int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      adjList[j].push_back(i);
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int k = 1; k <= K; k++) {
      if (k == 1) {
        memo[i][k] = 1;
      } else {
        ll ct = 0;
        for (auto x : adjList[i]) {
          ct = (ct + memo[x][k - 1]) % MOD;
        }
        memo[i][k] = ct;
      }
      if (k == K) ans = (ans + memo[i][k]) % MOD;
    }
  }
  cout << ans << endl;

  return 0;
}
