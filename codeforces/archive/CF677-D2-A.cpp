#include <bits/stdc++.h>
using namespace std;

int N, H;
int ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> H;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    ans += x <= H ? 1 : 2;
  }
  cout << ans << endl;

  return 0;
}
