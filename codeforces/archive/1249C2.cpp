#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Q;
ll N;

ll p(ll a, ll b) {
  if (b == 0) return 1;
  ll x = p(a, b / 2);
  return x * x * (b % 2 == 1 ? a : 1);
}

ll f(ll n) {
  ll x = (int)ceil(log(n) / log(3));
  ll below = (p(3, x) - 1) / 2;
  if (below < n) return p(3, x);
  ll y = p(3, x - 1);
  return y + f(n - y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> Q;
  for (int q = 0; q < Q; q++) {
    cin >> N;
    cout << f(N) << endl;
  }
  return 0;
}
