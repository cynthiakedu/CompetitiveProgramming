#include <bits/stdc++.h>
using namespace std;
int N, arr[2005];
map<int, int> f, s;
map<int, int> ct;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    f[arr[i]] = 0;
    s[arr[i]] = 0;
  }
  for (int i = N; i >= 1; i--) {
    int x = arr[i];
    if (f[x] == 0) {
      f[x] = i;
    } else if (s[x] == 0) {
      s[x] = i;
    }
  }

  bool good = true;
  for (auto p : s) {
    if (p.second > 0) {
      good = false;
    }
  }
  if (good) {
    cout << 0 << endl;
    return 0;
  }
  int ans = N;
  for (int i = 1; i <= N; i++) {
    int r = i;
    for (auto p : f) {
      if (ct[p.first] > 0) {
        r = max(r, p.second);
      } else {
        r = max(r, s[p.first]);
      }
    }
    ans = min(r - i + 1, ans);
    ct[arr[i]] += 1;
    if (ct[arr[i]] > 1) {
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
