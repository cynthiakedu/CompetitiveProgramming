#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K, A, X[100005], C[100005];
ll ans = 0;
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> X[i];
  cin >> A;
  for (int i = 1; i <= N; i++) cin >> C[i];

  for (int i = 1; i <= N; i++) {
    pq.push(-C[i]);
    while (K < X[i] && pq.size() > 0) {
      int c = -pq.top();
      pq.pop();
      ans += c;
      K += A;
    }
    if (K < X[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;

  return 0;
}
