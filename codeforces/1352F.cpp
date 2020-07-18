#include <bits/stdc++.h>
using namespace std;
int n0, n1, n2;
int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n0 >> n1 >> n2;

    if (n1 > 0 || n2 > 0) {
      cout << 1;
    }

    for (int i = 0; i < n2; i++) {
      cout << 1;
    }
    if (n1 > 0 || n0 > 0) {
      cout << 0;
    }
    for (int i = 0; i < n0; i++) {
      cout << 0;
    }
    for (int i = 0; i < n1 - 1; i++) {
      cout << (i % 2 ? 0 : 1);
    }
    cout << endl;
  }
  return 0;
}
