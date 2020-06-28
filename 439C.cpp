#include <bits/stdc++.h>
using namespace std;
int N, K, P;
vector<int> even, odd;
set<int> ans[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K >> P;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    if (x % 2 == 1) {
      odd.push_back(x);
    } else {
      even.push_back(x);
    }
  }
  if (odd.size() < K - P || ((odd.size() - (K - P)) % 2 == 1) ||
      ((odd.size() - (K - P)) / 2 + even.size() < P)) {
    cout << "NO" << endl;
    return 0;
  }

  int oddIdx = 0, evenIdx = 0;
  for (; oddIdx < K - P; oddIdx++) {
    ans[oddIdx].insert(odd[oddIdx]);
  }

  int idx = K - P;
  while (idx < K - 1) {
    if (oddIdx < odd.size()) {
      ans[idx].insert(odd[oddIdx]);
      ans[idx].insert(odd[oddIdx + 1]);
      oddIdx += 2;
    } else {
      ans[idx].insert(even[evenIdx]);
      evenIdx++;
    }
    idx++;
  }
  for (int i = oddIdx; i < odd.size(); i++) {
    ans[K - 1].insert(odd[i]);
  }
  for (int i = evenIdx; i < even.size(); i++) {
    ans[K - 1].insert(even[i]);
  }

  cout << "YES" << endl;
  for (int i = 0; i < K; i++) {
    cout << ans[i].size();
    for (auto x : ans[i]) cout << " " << x;
    cout << endl;
  }
  return 0;
}
