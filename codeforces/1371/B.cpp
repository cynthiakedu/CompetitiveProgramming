#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N, R;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> R;
    ll ans = 0;
    ll mn = min(R, N - 1);
    ans += mn * (mn + 1) / 2;
    if (R >= N)
      ans++;
    cout << ans << endl;
  }

  return 0;
}
