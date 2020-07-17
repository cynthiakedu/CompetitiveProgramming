#include <bits/stdc++.h>
using namespace std;
int N, arr[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  if (N == 1 || N == 2) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> a = {-1, 0, 1};
  int poss[12][2];  // start, diff
  int amt = 0;
  for (auto x : a) {
    for (auto y : a) {
      poss[amt][0] = arr[1] + x;
      poss[amt][1] = (arr[2] + y) - (arr[1] + x);
      amt++;
    }
  }

  int ans = INT_MAX;

  for (int i = 0; i < amt; i++) {
    bool tf = true;
    int ct = 0;
    for (int j = 1; j <= N; j++) {
      int need = poss[i][0] + (j - 1) * poss[i][1];
      if (abs(need - arr[j]) > 1) {
        tf = false;
        break;
      } else if (abs(need - arr[j]) == 1) {
        ct++;
      }
    }
    if (tf && ct < ans) {
      ans = ct;
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
