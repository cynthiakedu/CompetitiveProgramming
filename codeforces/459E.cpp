#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
int dp[300005];
vector<pair<int, ii>> edges;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0, u, v, w; i < M; i++) {
    cin >> u >> v >> w;
    edges.push_back({w, ii(u, v)});
  }

  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());

  int idx = 0;
  while (idx < edges.size()) {
    map<int, int> updates;
    int j = idx;
    while (j != edges.size() && edges[j].first == edges[idx].first) {
      int a = edges[j].second.first, b = edges[j].second.second;
      updates[a] = max(updates[a], dp[b] + 1);

      j++;
    }
    idx = j;
    for (auto p : updates) {
      dp[p.first] = max(dp[p.first], p.second);
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;

  return 0;
}
