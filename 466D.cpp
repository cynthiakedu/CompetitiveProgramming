#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int N, H;
int binom[2005][2005];
int arr[2005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int n = 1; n < 2005; n++) {
    for (int k = 0; k <= n; k++) {
      if (k == 0 || k == n) {
        binom[n][k] = 1;
      } else {
        binom[n][k] = (binom[n - 1][k - 1] + binom[n - 1][k]) % MOD;
      }
    }
  }

  cin >> N >> H;
  for (int i = 1, x; i <= N; i++) {
    cin >> x;
    if (x > H) {
      cout << 0 << endl;
      return 0;
    }
    arr[i] = H - x;
  }
  if (arr[1] > 1 || arr[N] > 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  for (int i = 2; i <= N; i++) {
    int a = arr[i - 1], b = arr[i];
    if (b == a - 1) {
      ans = (ans * a) % MOD;
    } else if (b == a) {
      ans = (ans * (a + 1)) % MOD;
    } else if (b == a + 1) {
      ans = ans;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << ans % MOD << endl;

  return 0;
}
