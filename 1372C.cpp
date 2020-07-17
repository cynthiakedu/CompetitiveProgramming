#include <bits/stdc++.h>
using namespace std;
int T, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    int num = 0;
    int ct = 0;
    bool tf = true;
    for (int i = 1, x; i <= N; i++) {
      cin >> x;
      if (x != i) {
        num++;
        tf = false;
      } else {
        if (num > 0) ct++;
        num = 0;
      }
    }
    if (num > 0) ct++;
    if (tf) {
      cout << 0 << endl;
    } else if (ct == 1) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }

  return 0;
}
