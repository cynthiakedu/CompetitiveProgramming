#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define T (1 << 18)
int N, M;
set<ii> S;

class LazySegTree {
 private:
  ii tree[2 * T];  // s, z
 public:
  LazySegTree() {}

  void update(int l, int r, ll val, int id = 1, int low = 0, int high = T) {
    // cout << "update l " << l << " r " << r << " val " << val << " id " << id
    //      << "low " << low << " high " << high << endl;
    // Propogate value of lazy update
    tree[id].first += (high - low) * tree[id].second;
    if (id < T) {
      tree[id * 2].second += tree[id].second;
      tree[id * 2 + 1].second += tree[id].second;
    }
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

  ll query(int l, int r, int id = 1, int low = 0, int high = T) {
    // cout << "query l " << l << " r " << r << " id " << id << "low " << low
    //      << " high " << high << endl;
    // Propogate value of lazy update
    tree[id].first += (high - low) * tree[id].second;
    if (id < T) {
      tree[id * 2].second += tree[id].second;
      tree[id * 2 + 1].second += tree[id].second;
    }
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

LazySegTree tree;

void processType1(int l, int r, int x) {
  //   cout << "Process type1 " << l << " " << r << " " << x << endl;
  set<ii>::iterator it = S.lower_bound(ii(l, LLONG_MIN));
  ii p = *it;
  if (p.second > 0) {
    S.insert(ii(l - 1, p.second));
    S.insert(ii(l, -p.second));
    it--;
  }
  while (it != S.end()) {
    ii p1 = *it;
    // cout << "p1 " << p1.first << " " << p1.second << endl;

    it++;
    ii p2 = *it;
    // cout << "p2 " << p2.first << " " << p2.second << endl;
    if (p1.first > r) {
      break;
    } else if (p2.first <= r) {
      //   cout << "Add " << p1.first << " " << p2.first << " " << endl;
      //   cout << "before " << p2.second << " after " << x
      //        << " diff = " << abs(p2.second - x) << endl;
      tree.update(p1.first, p2.first + 1, abs(p2.second - x));
      it++;
      //   ii p3 = *it;
      //   cout << "p3 " << p3.first << " " << p3.second << endl;
      //   cout << "p4 " << (*(prev(it))).first << " " << (*(prev(it))).second
      //        << endl;
      //   cout << "p5 " << (*(prev(prev(it)))).first << " "
      //        << (*(prev(prev(it)))).second << endl;

      S.erase(prev(it));
      S.erase(prev(it));
    } else {
      //   cout << "Add " << p1.first << " " << r << " " << endl;
      //   cout << "before " << p2.second << " after " << x
      //        << " diff = " << abs(p2.second - x) << endl;
      tree.update(p1.first, r + 1, abs(p2.second - x));
      S.erase(prev(it));
      S.insert(ii(r + 1, p1.second));
      break;
    }
  }
  S.insert(ii(l, -x));
  S.insert(ii(r, x));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //   LazySegTree tree;
  //   tree.update(1, 6, 3);
  //   tree.update(2, 8, 9);
  //   cout << tree.query(4, 7) << endl;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    S.insert(ii(i, -i));
    S.insert(ii(i, i));
  }
  for (int i = 0; i < M; i++) {
    int type, l, r;
    ll x;
    cin >> type;
    if (type == 1) {
      cin >> l >> r >> x;
      processType1(l, r, x);
    } else {
      cin >> l >> r;
      //   cout << "query " << l << " " << r << endl;
      cout << tree.query(l, r + 1) << endl;
    }
  }
}
