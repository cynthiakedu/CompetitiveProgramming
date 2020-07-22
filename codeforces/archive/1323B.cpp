#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K, A[400005], B[400005];
ll a[400005], b[400005];
ll cumA[400005], cumB[400005], cumCtA = 0, cumCtB = 0;
ll divA[400005], divB[400005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  int ctA = 0, ctB = 0;
  for (int i = 0; i < N; i++) {
    if (A[i]) {
      ctA++;
    } else {
      a[ctA]++;
      ctA = 0;
    }
  }
  a[ctA]++;
  for (int i = 0; i < M; i++) {
    if (B[i]) {
      ctB++;
    } else {
      b[ctB]++;
      ctB = 0;
    }
  }
  b[ctB]++;

  for (int i = 40000; i >= 1; i--) {
    cumA[i] = cumA[i + 1] + a[i];
    cumCtA += cumA[i];
    divA[i] = cumCtA;

    cumB[i] = cumB[i + 1] + b[i];
    cumCtB += cumB[i];
    divB[i] = cumCtB;
  }
  long long ans = 0;
  for (int i = 1; i <= 40000; i++) {
    if (K % i == 0 && K / i <= 40000) {
      ans += divA[i] * divB[K / i];
    }
  }
  cout << ans << endl;
  return 0;
}
