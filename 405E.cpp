#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, visited[100005];
map<int, int> adjList[100005];
vector<vector<int>> ANS;

void visit(int node, int component) {
  visited[node] = component;
  vector<int> v;
  //   cout << "node " << node << endl;
  for (auto p : adjList[node]) {
    // cout << "b1 " << p.first << " " << p.second << endl;
    if (visited[p.first] == -1) {
      adjList[node][p.first] = 2;
      adjList[p.first][node] = -1;
      visit(p.first, component);
    } else if (p.second != -1) {
      v.push_back(p.first);
    }
  }
  for (int idx = 0; idx < (int)v.size() - 1; idx += 2) {
    //   cout << "Node pairing " << node << " " << v[idx] << " " << v[idx + 1]
    //        << endl;
    ANS.push_back(vector<int>{v[idx], node, v[idx + 1]});
    adjList[node][v[idx]] = 1;
    adjList[node][v[idx + 1]] = 1;
    adjList[v[idx]][node] = -1;
    adjList[v[idx + 1]][node] = -1;
  }
}

vector<int> secondVisit(int node) {
  vector<int> v1, v2, v;

  for (auto p : adjList[node]) {
    if (p.second == 2) {
      vector<int> x = secondVisit(p.first);
      if (x.size() == 1) {
        ANS.push_back(vector<int>{x[0], p.first, node});
      } else if (x.size() == 0) {
        v1.push_back(p.first);
      }
    } else if (p.second == 0) {
      v2.push_back(p.first);
    }
  }

  for (auto x : v2) v.push_back(x);
  for (auto x : v1) v.push_back(x);
  for (auto x : v) {
    adjList[node][x] = 1;
    adjList[x][node] = -1;
  }

  //   cout << " V to pair for node " << node << endl;
  //   for (auto x : v) cout << x << endl;

  int idx = 0;
  for (; idx < (int)v.size() - 1; idx += 2) {
    //   cout << "Node pairing " << node << " " << v[idx] << " " << v[idx +
    //   1]
    //        << endl;
    ANS.push_back(vector<int>{v[idx], node, v[idx + 1]});
    // adjList[node][v[idx]] = 1;
    // adjList[node][v[idx + 1]] = 1;
    // adjList[v[idx]][node] = -1;
    // adjList[v[idx + 1]][node] = -1;
  }
  vector<int> ret;

  //   if (idx < v.size() && adjList[node][v[idx]] == 2) {
  if (idx < v.size()) {
    ret.push_back(v[idx]);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0, u, v; i < M; i++) {
    cin >> u >> v;
    adjList[u][v] = 0;
    adjList[v][u] = 0;
  }
  for (int i = 1; i <= N; i++) visited[i] = -1;

  int c = 1;
  for (int i = 1; i <= N; i++) {
    if (visited[i] == -1) {
      visit(i, c);
      secondVisit(i);
      c++;
    }
  }
  //   for (int i = 1; i <= N; i++) {
  //     cout << " AdjList for node " << i << endl;
  //     for (auto p : adjList[i]) {
  //       cout << p.first << " " << p.second << endl;
  //     }
  //   }
  map<int, int> count;
  for (int i = 1; i <= N; i++) {
    count[visited[i]] += adjList[i].size();
  }
  for (auto p : count) {
    if ((p.second / 2) % 2 == 1) {
      cout << "No solution" << endl;
      return 0;
    }
  }
  for (auto x : ANS) cout << x[0] << " " << x[1] << " " << x[2] << "\n";
  return 0;
}
// 8 4
// 1 2
// 3 4
// 5 6
// 7 8

// 5 4
// 1 2
// 2 3
// 3 4
// 4 5

// 7 6
// 1 3
// 2 3
// 3 4
// 4 5
// 4 7
// 4 6

// 7 10
// 1 2
// 2 3
// 3 7
// 3 5
// 2 5
// 5 7
// 4 5
// 6 7
// 1 4
// 4 6

// 4 6
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 3 4

// 5 4
// 1 2
// 1 3
// 1 4
// 1 5

// 5 6
// 1 2
// 1 3
// 3 5
// 3 4
// 1 4
// 2 5

// 4 4
// 1 3
// 3 2
// 1 2
// 2 4
