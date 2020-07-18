#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int N;
long double L, R, x[25], y[25], a[25];

long double extend(double curr, int idx) {
  long double ans;
  //   if (x[idx] <= curr) {
  long double theta = atan2((curr - x[idx]), y[idx]);
  ans = y[idx] * tan(theta + a[idx] * PI / 180) + x[idx];
  //   } else {
  //     long double theta = atan((x[idx] - curr) / y[idx]);
  //     ans = x[idx] - y[idx] * tan(theta - a[idx] * PI / 180);
  //   }

  //   cout << "extend " << curr << " " << idx << " " << ans << endl;
  return ans;
}

int main(int argc, const char *argv[]) {
  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> a[i];
  }

  long double dp[(1 << N) + 1];
  dp[0] = L;
  for (int i = 1; i < 1 << N; i++) {
    dp[i] = L;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        // cout << "memo " << i << " " << (i ^ (1 << j)) << endl;
        dp[i] = max(dp[i], extend(dp[i ^ (1 << j)], j));
      }
    }
  }
  cout << setprecision(10) << dp[(1 << N) - 1] - L << endl;
  //   x[0] = -161;
  //   y[0] = 565;
  //   a[0] = 4;
  //   cout << extend(451.421, 0) << endl;
  return 0;
}

// 5 -10000 2621
// 906 402 3X
// 334 64 7X
// -161 565 4
// 946 548 27 X
// 122 466 28X

//-8.3
// 107
// 181
// 122 466 --> 451.421