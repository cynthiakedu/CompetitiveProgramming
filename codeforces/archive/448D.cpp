#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, K;

ll ct(ll x) {
  ll ret = 0;
  for (int i = 1; i <= N; i++) {
    ret += min(x / i, M);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K;
  ll l = 1, r = M * N;
  while (l < r) {
    ll m = (l + r) / 2;
    ll c = ct(m);
    // cout << l << " " << r << " " << m << endl;
    // cout << "ct " << c << endl;
    if (c >= K) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << endl;

  return 0;
}
