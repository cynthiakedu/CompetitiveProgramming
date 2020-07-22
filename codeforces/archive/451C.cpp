#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, K, d1, d2;
vector<vector<ll>> v;
void solve() {
  for (auto i : vector<ll>{-1, 1}) {
    for (auto j : vector<ll>{-1, 1}) {
      // x, x + i*d1, x+i*d1+j*d2
      ll s = i * d1 + i * d1 + j * d2;
      if (K - s >= 0 && (K - s) % 3 == 0) {
        ll x = (K - s) / 3;
        v.push_back(vector<ll>{x, x + i * d1, x + i * d1 + j * d2});
      }
    }
  }

  for (auto x : v) {
    if (x[0] < 0 || x[1] < 0 || x[2] < 0) continue;
    ll m = max({x[0], x[1], x[2]});
    ll s = x[0] + x[1] + x[2];
    ll need = 3 * m - s;
    if (N - K >= need && (N - K - need) % 3 == 0) {
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> K >> d1 >> d2;
    v.clear();
    solve();
  }
  return 0;
}
