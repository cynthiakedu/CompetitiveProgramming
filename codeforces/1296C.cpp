#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int T, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    vector<ii> v;
    map<ii, int> l;
    int ans = INT_MAX, ansL, ansR;
    int a = 0, b = 0;
    v.push_back(ii(a, b));
    for (int i = 0; i < N; i++) {
      char c;
      cin >> c;
      if (c == 'R') a++;
      if (c == 'L') a--;
      if (c == 'U') b++;
      if (c == 'D') b--;
      v.push_back(ii(a, b));
    }
    l[v[0]] = 0;
    for (int i = 1; i <= N; i++) {
      if (l.count(v[i]) > 0) {
        int dist = i - l[v[i]];
        if (dist < ans) {
          ans = dist;
          ansL = l[v[i]] + 1;
          ansR = i;
        }
      }
      l[v[i]] = i;
    }
    if (ans == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << ansL << " " << ansR << endl;
    }
  }

  return 0;
}
