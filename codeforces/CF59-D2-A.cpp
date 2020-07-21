#include <bits/stdc++.h>
using namespace std;
string S;
int u = 0, l = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> S;
  for (char c : S) {
    if (isupper(c)) {
      u++;
    } else {
      l++;
    }
  }
  if (u > l) {
    string ans = "";
    for (auto c : S)
      ans += toupper(c);
    cout << ans << endl;
  } else {
    string ans = "";
    for (auto c : S)
      ans += tolower(c);
    cout << ans << endl;
  }

  return 0;
}
