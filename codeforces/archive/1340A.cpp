#include <bits/stdc++.h>
using namespace std;
int T, N, arr[100005];

void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 1; i < N; i++) {
    if (arr[i] > arr[i - 1] && arr[i] != arr[i - 1] + 1) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
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
