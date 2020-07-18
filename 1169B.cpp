#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, a[300005], b[300005];

bool solve(int x) {
  vector<ii> v;
  for (int i = 1; i <= M; i++) {
    if (!(a[i] == x || b[i] == x)) {
      v.push_back(ii(a[i], b[i]));
    }
  }
  if (v.size() == 0)
    return true;
  bool can1 = true, can2 = true;
  for (int i = 0; i < v.size(); i++) {
    if (!(v[i].first == v[0].first || v[i].second == v[0].first))
      can1 = false;
    if (!(v[i].first == v[0].second || v[i].second == v[0].second))
      can2 = false;
  }
  if (can1 || can2)
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;

  for (int i = 1; i <= M; i++) {
    cin >> a[i] >> b[i];
  }

  if (solve(a[1]) || solve(b[1])) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
