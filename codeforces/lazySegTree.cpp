#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define T (1 << 18)

class LazySegTree {
 private:
  pair<int, int> tree[2 * T];  // s, z
 public:
  LazySegTree() {}

  void update(int l, int r, int val, int id = 1, int low = 0, int high = T) {
    cout << "update l " << l << " r " << r << " val " << val << " id " << id
         << "low " << low << " high " << high << endl;
    // Propogate value of lazy update
    tree[id].first += (high - low) * tree[id].second;
    tree[id * 2].second += tree[id].second;
    tree[id * 2 + 1].second += tree[id].second;
    tree[id].second = 0;

    if (l <= low && r >= high) {
      tree[id].second += val;
      return;
    }
    tree[id].first += (min(r, high) - max(l, low)) * val;

    int mid = (low + high) / 2;
    if (r <= mid) return update(l, r, val, id * 2, low, mid);
    if (l >= mid) return update(l, r, val, id * 2 + 1, mid, high);
    update(l, r, val, id * 2, low, mid);
    update(l, r, val, id * 2 + 1, mid, high);
  }

  int query(int l, int r, int id = 1, int low = 0, int high = T) {
    cout << "query l " << l << " r " << r << " id " << id << "low " << low
         << " high " << high << endl;
    // Propogate value of lazy update
    tree[id].first += (high - low) * tree[id].second;
    tree[id * 2].second += tree[id].second;
    tree[id * 2 + 1].second += tree[id].second;
    tree[id].second = 0;

    if (l <= low && r >= high) {
      return tree[id].first;
    }

    int mid = (low + high) / 2;
    if (r <= mid) return query(l, r, id * 2, low, mid);
    if (l >= mid) return query(l, r, id * 2 + 1, mid, high);
    return query(l, r, id * 2, low, mid) + query(l, r, id * 2 + 1, mid, high);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << "here " << endl;
  //   pair<int, int> tree[2 * T];
  LazySegTree tree;
  tree.update(1, 6, 3);
  tree.update(2, 8, 9);
  cout << tree.query(4, 6) << endl;
}