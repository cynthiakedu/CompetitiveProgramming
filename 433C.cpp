#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, arr[100005];
vector<int> adj[100005];
ll totalSum = 0;
ll ans = LLONG_MAX;

ll calcSum(int x, vector<int> v) {
  ll s = 0;
  for (auto y : v) {
    s += abs(y - x);
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> arr[i];
  for (int i = 0; i < M - 1; i++) {
    int a = arr[i], b = arr[i + 1];
    if (a != b) {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    totalSum += abs(b - a);
  }
  ans = totalSum;
  for (int i = 1; i <= N; i++) {
    sort(adj[i].begin(), adj[i].end());
    ll original = calcSum(i, adj[i]);
    if (adj[i].size() == 0) continue;
    ans = min(ans, totalSum - original +
                       calcSum(adj[i][(adj[i].size()) / 2], adj[i]));
    if (adj[i].size() % 2 == 0) {
      int a = adj[i][(adj[i].size() - 1) / 2];
      int b = adj[i][(adj[i].size()) / 2];

      ans = min(ans, totalSum - original +
                         calcSum(adj[i][(adj[i].size() - 1) / 2], adj[i]));
      if ((a + b) % 2 == 0) {
        ans = min(ans, totalSum - original + calcSum((a + b) / 2, adj[i]));
      }
    }
  }
  cout << ans << endl;

  return 0;
}
