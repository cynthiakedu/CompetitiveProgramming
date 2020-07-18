#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;
ll N, M, K;

ll binom[2005][2005];

ll p(ll a, ll b) {
  if (b == 0)
    return 1;
  ll x = p(a, b / 2);
  return (((x * x) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int n = 1; n <= 2000; n++) {
    for (int k = 0; k <= n; k++) {
      if (k == 0 || k == n) {
        binom[n][k] = 1;
      } else {
        binom[n][k] = (binom[n - 1][k - 1] + binom[n - 1][k]) % MOD;
      }
    }
  }

  cin >> N >> M >> K;
  if (N == 1) {
    cout << M << endl;
  } else {
    cout << (((binom[N - 1][K] * M) % MOD) * p(M - 1, K)) % MOD << endl;
  }

  return 0;
}
