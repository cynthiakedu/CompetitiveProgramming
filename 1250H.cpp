#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    int a0;
    cin >> a0;
    int mn = INT_MAX, dig = 0;
    for (int i = 1, x; i <= 9; i++) {
      cin >> x;
      if (x < mn) {
        mn = x;
        dig = i;
      }
    }
    if (mn >= a0 + 1) {
      cout << 1;
      for (int i = 0; i <= a0; i++) cout << 0;
      cout << endl;
    } else {
      for (int i = 0; i <= mn; i++) cout << dig;
      cout << endl;
    }
  }

  return 0;
}
