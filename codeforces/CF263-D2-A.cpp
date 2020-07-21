#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ans;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int s;
      cin >> s;
      if (s == 1) {
        ans = abs(2 - i) + abs(2 - j);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
