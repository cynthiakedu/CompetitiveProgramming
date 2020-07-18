#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
// vector<ii> adjList[505];
map<int, ii> adjList[505];  //(weight, (node, edge))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0, u, v, w; i < M; i++) {
    cin >> u >> v >> w;
    adjList[u][v] = ii(w, 0);
    adjList[v][u] = ii(w, 0);
  }

  int ct = 0;
  for (int i = 1; i <= N; i++) {
    // cout << "Start from " << i << endl;
    vector<int> dist(N + 1, INT_MAX);
    dist[i] = 0;

    for (int i = 1; i <= N; i++) {
      for (auto p : adjList[i]) {
        adjList[i][p.first].second = 0;
      }
    }

    // vector<set<int>> parents(N + 1);
    priority_queue<pair<int, ii>> pq;
    pq.push(make_pair(0, ii(i, i)));

    while (!pq.empty()) {
      pair<int, ii> p = pq.top();
      int d = -p.first;
      //   cout << "visiting " << d << " " << p.second.first << " "
      //        << p.second.second << endl;
      pq.pop();
      if (d > dist[p.second.second]) continue;
      if (d == dist[p.second.second]) {
        if (p.second.first != p.second.second) {
          // parents[p.second.second].insert(p.second.first);
          adjList[p.second.second][p.second.first].second = 1;
        }
      }

      for (auto x : adjList[p.second.second]) {
        if (d + x.second.first <= dist[x.first]) {
          dist[x.first] = d + x.second.first;
          pq.push(
              make_pair(-(d + x.second.first), ii(p.second.second, x.first)));
        }
      }
    }
    // cout << "Parents" << endl;
    // for (int i = 1; i <= N; i++) {
    //   cout << "Parents for " << i << endl;
    //   for (auto x : parents[i]) cout << x << endl;
    // }
    // cout << "Parents" << endl;
    // for (int i = 1; i <= N; i++) {
    //   cout << "Parents for " << i << endl;
    //   for (auto x : adjList[i]) {
    //     if (x.second.second == 1) {
    //       cout << x.first << endl;
    //     }
    //   }
    // }
    vector<bool> vis(N + 1, false);
    queue<int> q;
    for (int j = i + 1; j <= N; j++) {
      fill(vis.begin(), vis.end(), false);
      q.push(j);
      int ans = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto x : adjList[u]) {
          if (x.second.second == 1) {
            ans++;
            q.push(x.first);
          }
        }
      }
      if (ct > 0) cout << " ";
      cout << ans;
      ct++;
      // cout << "ANS " << i << " " << j << " " << ans << endl;
    }
    // cout << "Dikstra from node " << i << endl;
  }
  cout << endl;

  return 0;
}
