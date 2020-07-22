#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll N, M;
ll MOD = 1000000007;

ll p(ll a, ll b) {
  if (b == 0) return 1;
  ll x = p(a, b / 2);
  return (((x * x) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  ll x = (p(2, M) + MOD - 1) % MOD;
  cout << p(x, N) << endl;

  return 0;
}
