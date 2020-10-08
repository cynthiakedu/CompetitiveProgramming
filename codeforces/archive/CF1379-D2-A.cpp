#include <bits/stdc++.h>
using namespace std;
int T, N;
string s;
string x = "abacaba";

int once(string y) {
  int idx = y.find(x, 0);
  if (idx != -1) {
    if (y.find(x, idx + 4) == -1) {
      return 1;
    } else {
      return 2;
    }
  }
  return 0;
}

void solve() {
  cin >> N;
  cin >> s;

  string t = s;

  for (int i = 0; i <= s.size() - x.size(); i++) {
    bool ok = 1;
    string t = s;
    for (int j = 0; j < x.size(); j++) {
      if (s[i + j] == '?') {
        t[i + j] = x[j];
      } else if (s[i + j] != x[j]) {
        ok = 0;
      }
    }
    ok &= once(t);
    if (ok) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
