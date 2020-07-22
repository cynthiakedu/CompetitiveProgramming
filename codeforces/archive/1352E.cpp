#include <bits/stdc++.h>
using namespace std;
int T, N;
int arr[8005], cum[8005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) cum[i] = cum[i - 1] + arr[i];
    for (int i = 1; i <= N; i++) {
      bool can = false;
      for (int j = 1; j <= N - 1; j++) {
        int pos =
            (int)(lower_bound(cum + j + 1, cum + N + 1, arr[i] + cum[j - 1]) -
                  cum);
        if (pos < N + 1 && cum[pos] == arr[i] + cum[j - 1]) {
          can = true;
          break;
        }
      }
      if (can) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
