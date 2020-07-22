#include <bits/stdc++.h>
using namespace std;
int T, N, arr[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    int big = arr[1];
    int mx = 0;
    for (int i = 2; i <= N; i++) {
      mx = max(mx, big - arr[i]);
      big = max(arr[i], big);
    }
    if (mx == 0) {
      cout << 0 << endl;
    } else {
      cout << 32 - __builtin_clz(mx) << endl;
    }
  }

  return 0;
}
