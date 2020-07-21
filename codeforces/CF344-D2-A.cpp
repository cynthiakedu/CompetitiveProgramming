#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
string s;
char c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (i == 0 || s[0] == c) {
      ans++;
    }
    c = s[1];
  }
  cout << ans << endl;

  return 0;
}
