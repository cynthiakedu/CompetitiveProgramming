#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M, K;
ll binom[70][70];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int n = 0; n <= 64; n++) {
    for (int k = 0; k <= n; k++) {
      if (k == 0 || k == n) {
        binom[n][k] = 1;
      } else {
        binom[n][k] = binom[n - 1][k - 1] + binom[n - 1][k];
      }
    }
  }

  cin >> M >> K;
  if ((M == 1 && K == 1) || M == 0) {
    cout << 1 << endl;
    return 0;
  }
  K -= 1;
  ll last = 64;
  ll ans = 0;
  for (int i = 0; i < K; i++) {
    ll ct = 0;
    ll l = K - i - 1;
    for (; l < last; l++) {
      ct += binom[l][K - i - 1];
      if (M <= ct) {
        ct -= binom[l][K - i - 1];

        break;
      }
    }
    last = l;
    M -= ct;
    ans += 1LL << l;
  }
  cout << ans + 1 << endl;
  return 0;
}
