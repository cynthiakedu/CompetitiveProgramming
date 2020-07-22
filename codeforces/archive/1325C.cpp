#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, leafCt = 0;
bool isLeaf[100005];
bool vis[100005];
vector<ii> adjList[100005];

void visit(int x, int e) {
  vis[x] = true;
  int ct = 0;
  for (auto y : adjList[x]) {
    if (!vis[y.first]) {
      ct++;
      visit(y.first, y.second);
    }
  }
  if (ct == 0) {
    leafCt++;
    isLeaf[e] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(ii(b, i));
    adjList[b].push_back(ii(a, i));
  }
  int node = 1;
  for (int i = 1; i <= N; i++) {
    if (adjList[i].size() > 1) {
      node = i;
      break;
    }
  }
  visit(node, -1);
  int l = 0;
  int nl = leafCt;

  for (int i = 0; i < N - 1; i++) {
    if (isLeaf[i]) {
      cout << l << endl;
      l++;
    } else {
      cout << nl << endl;
      nl++;
    }
  }

  return 0;
}
