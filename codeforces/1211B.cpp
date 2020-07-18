#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
ll mx = 0, mxX;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1, x; i <= N; i++) {
    cin >> x;
    if (x > mx) {
      mx = x;
      mxX = i;
    } else if (x == mx) {
      mxX = i;
    }
  }
  if (mx == 0) {
    cout << 0 << endl;
  } else {
    cout << N * (mx - 1) + mxX << endl;
  }

  return 0;
}
