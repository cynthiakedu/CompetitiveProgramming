// Adopted from kawatea

#include <bits/stdc++.h>
using namespace std;
int a[200000], N, M;
vector<vector<int>> op1s;
int b[7005][2];

int main(int argc, const char* argv[]) {
  cin >> N >> M;
  for (int i = 1; i < 200000; i++) {
    a[i] = i + 32 - __builtin_clz(i);
  }
  for (int i = 0; i < M; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int t, l, r, x;
      cin >> t >> l >> r >> x;
      op1s.push_back(vector<int>{t, l, r, x});
    } else {
      int t, v;
      cin >> t >> v;
      set<int> s;
      b[t][0] = v;
      b[t][1] = v;
      for (int j = t + 1; j <= N; j++) {
        b[j][0] = a[b[j - 1][0] - 1] + 1;
        b[j][1] = a[b[j - 1][1]];
      }

      for (int j = 0; j < (int)op1s.size(); j++)
        if (op1s[j][0] >= t) {
          int x1 = b[op1s[j][0]][0], y1 = b[op1s[j][0]][1];
          int x2 = op1s[j][1], y2 = op1s[j][2];
          bool disjoint = y2 < x1 || x2 > y1;
          if (!disjoint) s.insert(op1s[j][3]);
        }
      cout << s.size() << endl;
    }
  }
  return 0;
}
