#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define T (1 << 20)

int N, M, arr[200005], arr2[200005], parity[200005];
vector<int> adjList[200005];
ii intervals[200005];
map<int, int> getDirect;

class FenwickTree {
 private:
  vector<int> ft;

 public:
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= (b & (-b))) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void adjust(int k, int v) {
    // cout << "adjust " << k << " " << v << endl;
    for (; k < (int)ft.size(); k += (k & (-k))) {
      // cout << "k " << k << endl;
      ft[k] += v;
    }
  }
};

int ct = 0;
bool vis[200005];
ii visit(int node, int par) {
  parity[node] = par;
  vis[node] = true;
  bool isLeaf = true;
  int mn = INT_MAX, mx = INT_MIN;
  for (auto x : adjList[node])
    if (!vis[x]) {
      isLeaf = false;
      ii p = visit(x, 1 - par);
      mn = min(mn, p.first);
      mx = max(mn, p.second);
    }
  ii ret;
  if (isLeaf) {
    getDirect[node] = ct + 2;
    ret = ii(ct + 1, ct + 3);
    ct += 3;
  } else {
    ct += 3;
    getDirect[node] = mx + 2;
    ret = ii(mn, mx + 3);
  }
  intervals[node] = ret;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 1, x; i <= N; i++) cin >> arr[i];
  for (int i = 0, u, v; i < N - 1; i++) {
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  visit(1, 0);
  // for (int i = 1; i <= N; i++) {
  //   cout << "start/end " << i << " " << intervals[i].first << " "
  //        << intervals[i].second << endl;
  // }

  FenwickTree ftOdd(10 * N + 5);
  FenwickTree ftEven(10 * N + 2);

  for (int i = 0; i < M; i++) {
    int type, x, val;
    cin >> type;

    if (type == 1) {
      cin >> x >> val;
      int s = intervals[x].first, e = intervals[x].second;
      if (parity[x]) {
        ftOdd.adjust(s, val);
        ftOdd.adjust(e, -val);
      } else {
        ftEven.adjust(s, val);
        ftEven.adjust(e, -val);
      }

    } else {
      cin >> x;
      int child = getDirect[x];
      int diff = ftEven.rsq(1, child) - ftOdd.rsq(1, child);
      if (parity[x]) diff = -diff;
      cout << arr[x] + diff << endl;
    }
  }
  return 0;
}
// 6 11
// 1 2 1 1 2 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 1 2 3
// 1 1 2
// 1 5 4
// 1 3 5
// 1 6 1
// 2 1
// 2 2
// 2 3
// 2 4
// 2 5
// 2 6

// 5 5
// 1 2 1 1 2
// 1 2
// 1 3
// 2 4
// 2 5
// 1 2 3
// 1 1 2
// 2 1
// 2 2
// 2 5

// 6 2
// 1 2 1 1 2 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 1 1 2
// 2 1

// 6 2
// 1 2 1 1 2 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 1 1 2
// 2 1