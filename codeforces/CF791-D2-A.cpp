#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b;
  int t = 0;
  while (true) {
    a *= 3;
    b *= 2;
    t++;
    if (a > b) {
      cout << t << endl;
      return 0;
    }
  }
  return 0;
}
