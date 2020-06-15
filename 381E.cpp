// 381E
// 6/12/20
// Adopted from rng_58

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define T (1 << 20)

pair<int, int> tree[2 * T];
int N, M;
string s;

pair<int, int> merge(pair<int, int> p, pair<int, int> q) {
  pair<int, int> r = ii(p.first, q.second);
  if (p.second > q.first)
    r.second += p.second - q.first;
  else
    r.first += q.first - p.second;
  return r;
}

pair<int, int> f(int l, int r, int id = 1, int low = 0, int high = T) {
  if (l <= low && r >= high) return tree[id];
  int mid = (low + high) / 2;
  if (r <= mid) return f(l, r, id * 2, low, mid);
  if (l >= mid) return f(l, r, id * 2 + 1, mid, high);
  return merge(f(l, r, id * 2, low, mid), f(l, r, id * 2 + 1, mid, high));
}

int main(int argc, const char* argv[]) {
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    tree[T + i] = s[i] == '(' ? ii(0, 1) : ii(1, 0);

  for (int i = T - 1; i >= 1; i--)
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  cin >> M;
  for (int i = 0, l, r; i < M; i++) {
    cin >> l >> r;
    l--;
    pair<int, int> x = f(l, r);
    cout << r - l - x.first - x.second << endl;
  }

  return 0;
}
