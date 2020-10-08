#include <bits/stdc++.h>
using namespace std;
int N, T;
void solve() {
  int arr[1005] = {}, l[1005] = {}, r[1005] = {};

  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> arr[i];
  int lmn = 0, rmn = 0;
  for (int i = 1; i <= N; i++) {
    if (lmn && arr[i] > arr[lmn]) {
      l[i] = lmn;
    } else {
      lmn = i;
    }
  }
  for (int i = N; i >= 1; i--) {
    if (rmn && arr[i] > arr[rmn]) {
      r[i] = rmn;
    } else {
      rmn = i;
    }
  }
  for (int i = 1; i <= N; i++) {
    if (l[i] && r[i]) {
      cout << "YES" << endl;
      cout << l[i] << " " << i << " " << r[i] << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
