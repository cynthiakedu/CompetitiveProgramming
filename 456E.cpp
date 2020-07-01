#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
vector<int> adjList[300005];
int dsu[300005];
int p[300005], r[300005], l[300005];

int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }

bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

void unionSet(int i, int j) {
  if (!isSameSet(i, j)) {
    int x = findSet(i), y = findSet(j);
    int newLongPath = max({l[x], l[y], 1 + (l[x] + 1) / 2 + (l[y] + 1) / 2});
    // cout << "unionSet " << x << " " << y << " " << newLongPath << endl;
    if (r[x] > r[y]) {
      p[y] = x;
      l[x] = newLongPath;
    } else {
      p[x] = y;
      l[y] = newLongPath;
      if (r[x] == r[y]) r[y]++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> Q;
  for (int i = 1; i <= N; i++) p[i] = i;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    unionSet(u, v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  int visited[300005];
  for (int i = 0; i < 300005; i++) visited[i] = -1;
  vector<int> r2;

  for (int i = 1; i <= N; i++) {
    if (visited[i] == -1) {
      int maxV = i, maxD = 0;
      queue<int> q;
      q.push(i);
      visited[i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto x : adjList[u]) {
          if (visited[x] == -1) {
            visited[x] = visited[u] + 1;
            if (visited[x] > maxD) {
              maxV = x;
              maxD = visited[x];
            }
            q.push(x);
          }
        }
      }
      r2.push_back(maxV);
      //   cout << "pushed to r2 " << maxV << endl;
    }
  }

  for (int i = 0; i < 300005; i++) visited[i] = -1;
  for (auto r3 : r2) {
    int maxV = r3, maxD = 0;
    queue<int> q;
    q.push(r3);
    visited[r3] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto x : adjList[u]) {
        if (visited[x] == -1) {
          visited[x] = visited[u] + 1;
          if (visited[x] > maxD) {
            maxV = x;
            maxD = visited[x];
          }
          q.push(x);
        }
      }
    }
    l[findSet(r3)] = maxD;
    // cout << "storing max path " << findSet(r3) << " " << maxD << endl;
  }

  for (int i = 0; i < Q; i++) {
    int type, x, y;
    cin >> type;
    if (type == 1) {
      cin >> x;
      cout << l[findSet(x)] << endl;
    } else {
      cin >> x >> y;
      unionSet(x, y);
    }
  }
  return 0;
}

// 6 4 2
// 1 2
// 2 3
// 4 5
// 4 6
// 2 1 4
// 1 5