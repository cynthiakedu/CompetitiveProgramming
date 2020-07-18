#include <bits/stdc++.h>
using namespace std;
int T, N, arr[100005];
int mx = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    mx = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<int> v;
    int a = INT_MAX, b = INT_MIN;
    for (int i = 1; i < N; i++) {
      if (arr[i] != -1 && arr[i - 1] != -1) {
        mx = max(mx, abs(arr[i] - arr[i - 1]));
      } else {
        if (arr[i] != -1) {
          a = min(a, arr[i]);
          b = max(b, arr[i]);
        }
        if (arr[i - 1] != -1) {
          a = min(a, arr[i - 1]);
          b = max(b, arr[i - 1]);
        }
      }
    }
    if (a == INT_MAX) {
      cout << 0 << " " << 1 << endl;
    } else {
      int ans = (a + b) / 2;
      int ans2 = max({abs(ans - a), abs(ans - b), mx});
      cout << ans2 << " " << ans << endl;
    }
  }

  return 0;
}
