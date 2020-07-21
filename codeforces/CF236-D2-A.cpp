#include <bits/stdc++.h>
using namespace std;
set<char> S;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  for (auto c : s) {
    S.insert(c);
  }
  cout << (S.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << endl;

  return 0;
}
