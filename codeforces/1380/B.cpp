#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int t = 0; t < T; t++) {
    string s;
    cin >> s;
    map<char, int> ct = {{'R', 0}, {'P', 0}, {'S', 0}};
    map<char, char> m = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int mx = 0;
    char mxc;
    for (auto c : s) {
      ct[c]++;
    }
    for (auto p : ct) {
      if (p.second > mx) {
        mx = p.second;
        mxc = p.first;
      }
    }
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
      ans += m[mxc];
    }
    cout << ans << endl;
  }

  return 0;
}
