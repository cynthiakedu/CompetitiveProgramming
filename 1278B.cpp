#include <bits/stdc++.h>
using namespace std;
int T, a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> a >> b;
    int diff = abs(a - b);
    int n = (int)floor(pow(2 * diff, 1.0 / 2));
    while (true) {
      if (n * (n + 1) / 2 >= diff && (n * (n + 1) / 2) % 2 == diff % 2) {
        cout << n << endl;
        break;
      }
      n++;
    }
  }

  return 0;
}
