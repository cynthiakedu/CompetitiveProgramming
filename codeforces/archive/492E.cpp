#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, dx, dy;

// inverse of a modulo b, between 1 and b inclusive
ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
int ct[1000005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> dx >> dy;
  for (int i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    ll steps = (b * inv(dy, N)) % N;
    ll x = (a - steps * dx + N * N) % N;
    ct[(int)x]++;
  }
  int ansX = 0, mx = 0;
  for (int i = 0; i < N; i++) {
    if (ct[i] > mx) {
      mx = ct[i];
      ansX = i;
    }
  }
  cout << ansX << " " << 0 << endl;

  return 0;
}
