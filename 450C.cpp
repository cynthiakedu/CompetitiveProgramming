// MemS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K;
  ll ans = 0;
  if (K > (N - 1) + (M - 1)) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 1; i <= sqrt(N); i++) {
    int x = min(N / i - 1, K);
    ans = max(ans, 1ll * i * (M / (K - x + 1)));
    x = min(i - 1, K);
    ans = max(ans, 1ll * (N / (x + 1)) * (M / (K - x + 1)));
  }
  cout << ans << endl;

  return 0;
}
