#include <bits/stdc++.h>
using namespace std;
int T, A, B, C;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    int x, y, z;
    cin >> A >> B >> C;
    if (C < A) swap(A, C);
    x = A;
    y = C / 2;
    z = C - C / 2;

    int mx = max({x, y, z});
    int spc = 3 * mx - (x + y + z);
    if (spc >= B) {
      cout << mx << endl;
    } else {
      B -= spc;
      cout << mx + (B + 2) / 3 << endl;
    }
  }

  return 0;
}
