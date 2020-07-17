#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
string s, t;
vector<int> pos1, pos2;
vector<ii> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cin >> s >> t;
  for (int i = 0; i < N; i++) {
    if (s[i] != t[i]) {
      if (s[i] == 'a') {
        pos1.push_back(i);
      } else {
        pos2.push_back(i);
      }
    }
  }
  if (pos1.size() % 2 != pos2.size() % 2) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < pos1.size() / 2; i++) {
    int a = pos1[i];
    int b = pos1[pos1.size() - 1 - i];
    ans.push_back(ii(a, b));
  }
  for (int i = 0; i < pos2.size() / 2; i++) {
    int a = pos2[i];
    int b = pos2[pos2.size() - 1 - i];
    ans.push_back(ii(a, b));
  }
  if (pos1.size() % 2 == 1) {
    int a = pos1[pos1.size() / 2];
    int b = pos2[pos2.size() / 2];
    ans.push_back(ii(a, a));
    ans.push_back(ii(a, b));
  }
  cout << ans.size() << endl;
  for (auto x : ans) cout << x.first + 1 << " " << x.second + 1 << endl;

  return 0;
}
