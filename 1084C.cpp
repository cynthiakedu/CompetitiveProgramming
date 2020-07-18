#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

string s;
ll ct = 0;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;

  for (auto c : s) {
    if (c == 'a') {
      ct = (ct + 1) % MOD;
    } else if (c == 'b') {
      if (ct > 0) {
        v.push_back(ct);
        ct = 0;
      }
    }
  }

  if (ct > 0) {
    v.push_back(ct);
  }

  ll ans = 0;
  for (auto c : v) {
    ans = ((ans * (1 + c)) % MOD + c) % MOD;
  }
  cout << ans << endl;

  return 0;
}
