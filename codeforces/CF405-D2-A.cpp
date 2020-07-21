#include <bits/stdc++.h>
using namespace std;
int N, arr[105], amt[105] = {}, cum[105] = {};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    amt[x]++;
  }
  for (int i = 100; i >= 1; i--) {
    cum[i] = cum[i + 1] + amt[i];
  }

  for (int i = 1; i <= N; i++) {
    int ans = 0;
    for (int j = 1; j <= 100; j++) {
      if (cum[j] >= N + 1 - i) {
        ans++;
      }
    }
    cout << ans << (i == N ? "\n" : " ");
  }

  return 0;
}
