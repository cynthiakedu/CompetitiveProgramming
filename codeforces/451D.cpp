#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[2], b[2];
ll o, e;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  for (char c : s) {
    if (c == 'a') {
      a[0]++;
      o += a[0];
      e += a[1];
    } else {
      b[0]++;
      o += b[0];
      e += b[1];
    }

    swap(a[0], a[1]);
    swap(b[0], b[1]);
    // cout << b[0] << " " << b[1] << " " << a[0] << " " << a[1] << endl;
    // cout << "o e " << o << " " << e << endl;
  }
  cout << e << " " << o << endl;

  return 0;
}
