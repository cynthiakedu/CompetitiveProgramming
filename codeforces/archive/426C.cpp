#include <bits/stdc++.h>
using namespace std;
int N, K, arr[205];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  int ans = INT_MIN;
  for (int l = 1; l <= N; l++) {
    for (int r = l; r <= N; r++) {
      //   cout << "l/r " << l << " " << r << endl;
      vector<int> vin, vout;
      int s = 0;
      for (int k = 1; k <= N; k++) {
        if (l <= k && k <= r) {
          vin.push_back(arr[k]);
          s += arr[k];
        } else {
          vout.push_back(arr[k]);
        }
      }
      //   cout << "sum " << s << endl;
      ans = max(ans, s);
      sort(vin.begin(), vin.end());
      sort(vout.begin(), vout.end());
      for (int k = 1; k <= min({(int)vin.size(), (int)vout.size(), K}); k++) {
        int sumBefore = 0, sumAfter = 0;
        for (int a = 0; a < k; a++) {
          sumBefore += vin[a];
          sumAfter += vout[(int)vout.size() - k + a];
        }
        // cout << "k " << k << " " << sumBefore << " " << sumAfter << endl;
        ans = max(ans, s - sumBefore + sumAfter);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
