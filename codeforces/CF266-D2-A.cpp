#include <bits/stdc++.h>
using namespace std;
int N;
string S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> S;
  int ans = 0;
  int idx = 0;
  while (idx < N) {
    int j = idx;
    while (j < N && S[j] == S[idx]) {
      j++;
    }
    ans += (j - idx - 1);
    idx = j;
  }
  cout << ans << endl;
  return 0;
}
