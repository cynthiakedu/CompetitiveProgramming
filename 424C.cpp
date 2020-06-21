#include <bits/stdc++.h>
using namespace std;
int N, arr[1000005];
int cum[1000005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int ans;
  cin >> ans;
  for (int i = 1, x; i < N; i++) {
    cin >> x;
    ans = ans ^ x;
  }
  cum[1] = 1;
  for (int i = 2; i <= N; i++) {
    cum[i] = cum[i - 1] ^ i;
  }

  for (int i = 1; i <= N; i++) {
    int first = N % (2 * i);
    if (first >= i) {
      ans = ans ^ cum[i - 1];
      first -= i;
    }
    ans = ans ^ cum[first];
  }
  cout << ans << endl;
  return 0;
}
