#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;

ll gcd(ll x, ll y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  ll ans = N;
  for (ll i = 2; i <= sqrt(N); i++) {
    if (N % i == 0) {
      ans = gcd(ans, i);
      ans = gcd(ans, N / i);
    }
  }

  cout << ans << endl;
  return 0;
}
