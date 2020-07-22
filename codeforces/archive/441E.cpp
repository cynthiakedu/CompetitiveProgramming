#include <bits/stdc++.h>
using namespace std;
double X, P;
int K;
double memo[205][205];

double v2(int x) {
  double ret = 0;
  while (x % 2 == 0) {
    x /= 2;
    ret++;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> X >> K >> P;

  for (int k = 0; k <= K; k++) {
    for (int i = 0; i <= K; i++) {
      if (k == 0) {
        memo[k][i] = v2(X + i);
        continue;
      }
      double prob = 0;
      for (int j = 0; j < k; j++) {
        prob = pow((100 - P) / 100, j) * P / 100;
        if ((i + j) % 2 == 0) {
          memo[k][i] += prob * (memo[k - (j + 1)][(i + j) / 2] + 1);
        }
      }
      prob = pow((100 - P) / 100, k);
      memo[k][i] += prob * v2(X + k + i);
      //   cout << "memo " << k << " " << i << " " << memo[k][i] << endl;
    }
  }
  cout << setprecision(20) << memo[K][0] << endl;

  return 0;
}
