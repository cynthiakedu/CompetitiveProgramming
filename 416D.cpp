#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll a[200005];
ll a1 = -2, a2;
ll maxNext[200005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  a2 = N + 1;
  for (int i = 1; i <= N; i++) cin >> a[i];

  for (int i = N; i >= 1; i--) {
    // cout << "Starting, i = " << i << " a1, a2 = " << a1 << " " << a2 << endl;
    if (a1 == -2) {
      maxNext[i] = a2 - 1;
    } else {
      if (a[i] == -1) {
        maxNext[i] = a2 - 1;
      } else {
        maxNext[i] = a1 - 1;
      }

      if (a[i] != -1 && a1 != -2 && (a[a1] - a[i]) % (a1 - i) == 0) {
        ll diff = (a[a1] - a[i]) / (a1 - i);
        maxNext[i] =
            max(maxNext[i],
                diff >= 0 ? a2 - 1
                          : min(i + (ll)(a[i] + abs(diff) - 1) / abs(diff) - 1,
                                (ll)a2 - 1));
      }

      if (a2 != N + 1 && maxNext[a1] >= a2) {
        ll diff = (a[a1] - a[a2]) / (a2 - a1);
        ll num = a[a2] + diff * (a2 - i);
        if (num > 0 && !(a[i] != -1 && a[i] != num)) {
          maxNext[i] = max(maxNext[i], maxNext[a1]);
        }
      }
    }

    if (a[i] != -1) {
      if (a1 != -2) a2 = a1;
      a1 = i;
    }
    // cout << "result for i = " << i << " " << maxNext[i] << endl;
  }

  int idx = 1;
  int ans = 0;
  while (idx < N + 1) {
    idx = maxNext[idx] + 1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}

// 13
// -1 -1 -1 6 -1 2 -1 4 7 -1 2 -1 -1
