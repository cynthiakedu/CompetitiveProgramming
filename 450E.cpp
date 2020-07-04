#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
int a[100005];
map<int, vector<int>> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < 100005; i++) a[i] = -1;
  for (int i = 2; i <= N; i++) {
    if (a[i] == -1) {
      vector<int> v;
      for (int j = i; j <= N; j += i) {
        if (a[j] == -1) {
          a[j] = i;
          v.push_back(j);
        }
      }
      m[i] = v;
    }
  }
  vector<int> odd;
  vector<ii> ans;
  int extra = 0;
  for (auto p : m) {
    if (p.first != 2) {
      vector<int> v = p.second;
      int idx = 0;
      if ((int)v.size() % 2 == 1) {
        if (p.first * 2 <= N) {
          ans.push_back(ii(p.first * 2, p.first));
          m[2].erase(lower_bound(m[2].begin(), m[2].end(), p.first * 2));
        }
        idx = 1;
      }
      while (idx < v.size()) {
        ans.push_back(ii(v[idx], v[idx + 1]));
        idx += 2;
      }
    }
  }
  int idx = 0;
  while (idx < m[2].size() - 1) {
    ans.push_back(ii(m[2][idx], m[2][idx + 1]));
    idx += 2;
  }

  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first << " " << p.second << "\n";
  }
  return 0;
}
