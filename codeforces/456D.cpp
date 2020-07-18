#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, K;
unordered_map<int, set<int>> m;
int dp[28000005];

int visit(int p) {
  if (m[p].size() == 0) return 4;
  if (0 <= p && p < 28000005 && dp[p] != -1) {
    return dp[p];
  }

  bool win = false, lose = false, is2 = false;
  int ct[5];
  for (int i = 1; i <= 4; i++) ct[i] = 0;
  for (auto p1 : m[p]) {
    int r = visit(p1);
    ct[r]++;
  }
  int ret;
  if (ct[2] > 0)
    ret = 1;
  else if (ct[3] > 0 && ct[4] > 0)
    ret = 1;
  else if (ct[3])
    ret = 4;
  else if (ct[4])
    ret = 3;
  else
    ret = 2;
  if (0 <= p && p < 28000005) {
    dp[p] = ret;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    m[-1].insert(s[0] - 'a');

    for (int j = 1; j < s.size(); j++) {
      m[(j - 1) * 27 + (s[j - 1] - 'a')].insert(j * 27 + (s[j] - 'a'));
    }
  }
  for (int i = 0; i < 28000005; i++) dp[i] = -1;
  int res = visit(-1);

  if (res == 1) {
    cout << "First"
         << "\n";
  } else if (res == 2) {
    cout << "Second"
         << "\n";
  } else if (res == 3) {
    cout << (K % 2 == 1 ? "First" : "Second") << "\n";
  } else {
    cout << "Second"
         << "\n";
  }
  return 0;
}

// 4 5
// acef
// acegh
// acd
// ab
