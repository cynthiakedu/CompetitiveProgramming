#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, A, B, N, M;

void solve() {
  cin >> A >> B >> N >> M;
  if ((A + B) < (N + M)) {
    cout << "No" << endl;
    return;
  }
  if (M > min(A, B)) {
    cout << "No" << endl;
    return;
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
}