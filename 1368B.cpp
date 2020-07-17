#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> K;
  double x = ceil(pow(K, 1.0 / 10));
  ll mn = LLONG_MAX;
  vector<char> cf = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
  vector<int> ans;
  for (int i = 0; i < 1 << 10; i++) {
    ll s = 0, p = 1;
    vector<int> v;
    for (int j = 0; j < 10; j++) {
      if (i & (1 << j)) {
        s += x;
        p *= x;
        v.push_back(x);
      } else {
        s += x - 1;
        p *= x - 1;
        v.push_back(x - 1);
      }
    }
    if (p >= K && s < mn) {
      mn = s;
      ans = v;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < ans[i]; j++) {
      cout << cf[i];
    }
  }
  cout << endl;

  return 0;
}
