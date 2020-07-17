#include <bits/stdc++.h>
using namespace std;
int N, M, a[2005], b[2005];
int ans = INT_MAX;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];

  for (int i = 0; i < N; i++) {
    map<int, int> bMap, aMap;
    for (int j = 0; j < N; j++) bMap[b[j]] += 1;

    int x = (b[i] - a[0] + M) % M;
    bool poss = true;
    for (int j = 0; j < N; j++) {
      int num = (a[j] + x) % M;
      if (bMap[num] <= 0) {
        poss = false;
        break;
      }
      bMap[num]--;
    }
    if (poss) {
      ans = min(ans, x);
    }
  }
  cout << ans << endl;

  return 0;
}
