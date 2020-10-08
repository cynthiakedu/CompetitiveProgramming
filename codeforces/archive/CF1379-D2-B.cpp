#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long T, L, R, M;

void solve() {
  cin >> L >> R >> M;

  for (ll a = L; a <= R; a++) {
    ll n = M / a, c = L, b;
    if (n >= 1) {
      b = c + M % a;
      if (L <= b && b <= R) {
        cout << a << " " << b << " " << c << endl;
        return;
      }
    }
    ll diff = (n + 1) * a - M;
    b = L, c = L + diff;
    if (L <= c && c <= R) {
      cout << a << " " << b << " " << c << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }

  return 0;
}
