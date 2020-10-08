#include <bits/stdc++.h>
using namespace std;
int T, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    cout << (N + 1) / 2 << endl;
  }

  return 0;
}
