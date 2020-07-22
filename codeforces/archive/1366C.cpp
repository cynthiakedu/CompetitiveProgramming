#include <bits/stdc++.h>
using namespace std;
int T, N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> M;
    int ans = 0;
    map<int, map<int, int>> m;
    map<int, int> c;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        int x;
        cin >> x;
        if ((N + M) % 2 == 0 && i + j == (N + M + 2) / 2) continue;

        m[min(i + j, N + M + 2 - (i + j))][x] += 1;
        c[min(i + j, N + M + 2 - (i + j))] += 1;
      }
    }
    for (auto p : m) {
      int mx = 0;
      for (auto x : p.second) {
        if (x.second >= mx) {
          mx = x.second;
        }
      }
      ans += c[p.first] - mx;
    }
    cout << ans << endl;
  }

  return 0;
}
