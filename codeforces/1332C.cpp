#include <bits/stdc++.h>
using namespace std;
int T, N, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> K;
    int ans = 0;
    map<int, set<int>> s;
    map<int, vector<char>> m;
    for (int i = 0; i < N; i++) {
      char c;
      cin >> c;
      m[i % K].push_back(c);
    }
    for (int i = 0; i <= (N - 1) / 2; i++) {
      int a = i % K, b = (N - 1 - i + K) % K;
      s[min(a, b)].insert(a);
      s[min(a, b)].insert(b);
    }
    for (auto p : s) {
      int total = 0, mx = 0;
      map<int, int> ct;
      for (auto x : p.second) {
        for (auto y : m[x]) {
          ct[y] += 1;
          total += 1;
        }
      }
      for (auto x : ct) {
        mx = max(mx, x.second);
      }
      ans += total - mx;
    }
    cout << ans << endl;
  }

  return 0;
}
