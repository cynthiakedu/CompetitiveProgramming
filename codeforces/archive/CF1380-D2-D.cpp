#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, a[200005], b[200005];
ll X, Y, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  cin >> X >> K >> Y;
  a[0] = 0;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  a[N + 1] = 0;
  b[0] = 0;
  for (int i = 1; i <= M; i++)
    cin >> b[i];
  b[M + 1] = 0;
  int ans = 0;

  int i1 = 0;
  for (int i2 = 1; i2 <= M + 1; i2++) {
    int r = i1;
    while (r <= N + 1 && a[r] != b[i2]) {
      r++;
    }
    // cout << i1 << " " << r << endl;
    if (r == N + 2) {
      cout << -1 << endl;
      return 0;
    }

    vector<int> v;
    for (int i = i1 + 1; i < r; i++) {
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int pos =
        (int)(upper_bound(v.begin(), v.end(), max(a[i1], a[r])) - v.begin());

    ll amt = v.size();
    int bigAmt = pos < v.size() ? 1 : 0;

    ll tmp;
    if (pos < v.size()) {
      if (amt < K) {
        tmp = LLONG_MAX;
      } else {
        tmp = X + (amt / K - 1) * min(X, Y * K) + (amt % K) * Y;
      }
    } else {
      tmp = (amt / K) * min(X, Y * K) + (amt % K) * Y;
    }
    if (tmp == LLONG_MAX) {
      cout << -1 << endl;
      return 0;
    }
    ans += tmp;

    i1 = r;
  }
  cout << ans << endl;

  return 0;
}
// 7 2
// 5 2 3
// 3 1 4 6 5 9 2
// 3 5

// 5 2
// 5 2 3
// 3 9 8 7 2
// 3 2

// 6 2
// 5 2 1
// 3 2 4 1 6 7
// 3 2

// 6 2
// 5 3 1
// 3 9 7 4 1 2
// 3 2

// 4 1
// 5 3 1
// 4 2 5 6
// 4