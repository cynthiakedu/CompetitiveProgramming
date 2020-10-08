#include <bits/stdc++.h>
using namespace std;
string s1, s2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++) {
    char a = tolower(s1[i]), b = tolower(s2[i]);
    if (a < b) {
      cout << -1 << endl;
      return 0;
    } else if (a > b) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}
