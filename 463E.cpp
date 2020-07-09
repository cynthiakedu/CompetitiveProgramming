#include <bits/stdc++.h>
using namespace std;
int N, Q, arr[100005];
vector<int> primes[2000005];
vector<int> adjList[100005];

int dist[100005], ans[100005];
bool isComp[2000005];
map<int, int> pToNode;

void visit(int x) {
  int res = -1, d = -1;
  map<int, int> ori;
  for (auto p : primes[arr[x]]) {
    int node = pToNode[p];
    if (node != -1 && dist[node] > d) {
      res = node;
      d = dist[node];
    }
    ori[p] = node;
    pToNode[p] = x;
  }
  ans[x] = res;

  for (auto y : adjList[x]) {
    if (dist[y] == -1) {
      dist[y] = dist[x] + 1;
      visit(y);
    }
  }

  // restore
  for (auto p : ori) {
    pToNode[p.first] = p.second;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < 2000005; i++) {
    if (!isComp[i]) {
      pToNode[i] = -1;
      for (int j = i; j < 2000005; j += i) {
        primes[j].push_back(i);
        isComp[j] = true;
      }
    }
  }
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 0, x, y; i < N - 1; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  for (int i = 0; i < 100005; i++) ans[i] = -1;
  for (int i = 0; i < 100005; i++) dist[i] = -1;
  dist[1] = 0;
  visit(1);
  for (int i = 0; i < Q; i++) {
    int type, v, w;
    cin >> type;
    if (type == 1) {
      cin >> v;
      cout << ans[v] << endl;
    } else {
      cin >> v >> w;
      arr[v] = w;
      for (int i = 0; i < 100005; i++) dist[i] = -1;
      for (int i = 0; i < 100005; i++) ans[i] = -1;
      dist[1] = 0;
      for (auto p : pToNode) pToNode[p.first] = -1;
      visit(1);
    }
  }
  return 0;
}
