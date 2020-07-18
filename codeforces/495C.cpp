#include <bits/stdc++.h>
using namespace std;
string s;
int l1 = 0, l2 = 0, r2 = 0;
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ')') {
      r2++;
    } else if (s[i] == '(') {
      l2++;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    cout << l1 << " " << l2 << " " << r2 << endl;
    if (s[i] == '(') {
      l1++;
      l2--;
    } else if (s[i] == ')') {
      if (l1 == 0) {
        cout << -1 << endl;
        return 0;
      }
      l1--;
      r2--;
    } else {
      if (r2 < l1 + l2) {
        int red = min((l1 + l2) - r2, l1);
        ans.push_back(red);
        l1 -= red;
      }
    }
  }
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << (i == (ans.size() - 1) ? "\n" : " ");
  return 0;
}
