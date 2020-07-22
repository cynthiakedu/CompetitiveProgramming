#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
string sl, sr;

map<int, vector<int>> l, r;
vector<int> noL, noR;
vector<ii> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  cin >> sl >> sr;
  for (int i = 0; i < N; i++) {
    l[sl[i]].push_back(i);
    r[sr[i]].push_back(i);
  }

  for (int i = 0; i < 26; i++) {
    vector<int> x = l[(char)('a' + i)], y = r[(char)('a' + i)];
    if (x.size() <= y.size()) {
      for (int j = 0; j < x.size(); j++) {
        ans.push_back(ii(x[j], y[j]));
      }
      for (int j = x.size(); j < y.size(); j++) {
        noR.push_back(y[j]);
      }
    } else {
      for (int j = 0; j < y.size(); j++) {
        ans.push_back(ii(x[j], y[j]));
      }
      for (int j = y.size(); j < x.size(); j++) {
        noL.push_back(x[j]);
      }
    }
  }

  vector<int> qL = l['?'], qR = r['?'];
  vector<int> qL1, qR1;
  for (int i = 0; i < min(qL.size(), noR.size()); i++) {
    ans.push_back(ii(qL[i], noR[i]));
  }
  for (int i = min(qL.size(), noR.size()); i < qL.size(); i++) {
    qL1.push_back(qL[i]);
  }
  for (int i = 0; i < min(qR.size(), noL.size()); i++) {
    ans.push_back(ii(noL[i], qR[i]));
  }
  for (int i = min(qR.size(), noL.size()); i < qR.size(); i++) {
    qR1.push_back(qR[i]);
  }
  for (int i = 0; i < min(qL1.size(), qR1.size()); i++) {
    ans.push_back(ii(qL1[i], qR1[i]));
  }

  cout << ans.size() << endl;
  for (auto x : ans)
    cout << x.first + 1 << " " << x.second + 1 << endl;

  return 0;
}
