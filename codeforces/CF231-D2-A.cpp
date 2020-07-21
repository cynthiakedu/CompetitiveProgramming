#include <bits/stdc++.h>
using namespace std;
int N, a, b, c, ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    if (a + b + c >= 2) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
