#include <bits/stdc++.h>
using namespace std;

int N, arr[150005];
set<int> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  sort(arr + 1, arr + N + 1);

  int ans = 0;

  for (int i = N; i >= 1; i--) {
    int x = arr[i];
    if (s.count(x + 1) == 0) {
      s.insert(x + 1);
      ans++;
    } else if (s.count(x) == 0) {
      s.insert(x);
      ans++;
    } else if (x > 1 && s.count(x - 1) == 0) {
      s.insert(x - 1);
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
