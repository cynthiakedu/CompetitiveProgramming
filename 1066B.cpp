#include <bits/stdc++.h>
using namespace std;
int N, R, arr[1005];
vector<int> v;
int idx = 1;
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> R;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      v.push_back(i);
    }
  }
  while (idx <= N) {
    int pos = (int)(upper_bound(v.begin(), v.end(), idx + (R - 1)) - v.begin());
    if (pos == 0 || v[pos - 1] < idx - (R - 1)) {
      cout << -1 << endl;
      return 0;
    }
    ans++;
    idx = v[pos - 1] + R;
  }
  cout << ans << endl;
  return 0;
}
