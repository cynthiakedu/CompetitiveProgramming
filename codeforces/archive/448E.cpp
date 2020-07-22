#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000
ll X, K;
vector<ll> d;
map<ll, vector<ll>> d2;

vector<ll> f(ll k) {
  vector<ll> ans;
  if (k == 0) {
    return vector<ll>{X};
  } else if (k % 2 == 1) {
    vector<ll> v = f(k - 1);
    for (auto x : v) {
      for (auto x1 : d2[x]) {
        ans.push_back(x1);
      }
    }
  } else {
    vector<ll> v = f(k / 2);
    vector<ll> prevAns, prevAns2;
    map<ll, pair<int, int>> pos;
    int pre = -1, idx = 0;
    for (auto x : d) {
      while (idx < v.size() && v[idx] != x) {
        idx++;
      }
      pos[x] = pair<int, int>(pre + 1, idx == v.size() ? v.size() - 1 : idx);
      pre = idx;
      if (idx == v.size()) break;
    }
    for (auto x : d) {
      if (x != X) {
        if (pos.count(x) > 0) {
          for (int i = pos[x].first; i <= pos[x].second; i++) {
            prevAns.push_back(v[i]);
          }
        }
      }
    }
    for (auto x : prevAns) {
      if (pos.count(x) > 0) {
        for (int i = pos[x].first; i <= pos[x].second; i++) {
          prevAns2.push_back(v[i]);
        }
      }
    }

    for (auto x : prevAns2) {
      for (auto x1 : d2[x]) {
        ans.push_back(x1);
      }
      if (ans.size() > MAX) {
        return ans;
      }
    }
    for (auto x : v) {
      ans.push_back(x);
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> X >> K;
  for (int i = 1; i <= (int)sqrt(X); i++) {
    if (X % i == 0) {
      d.push_back(i);
      if (i * i != X) {
        d.push_back(X / i);
      }
    }
  }
  sort(d.begin(), d.end());
  for (auto x : d) {
    vector<ll> v;
    for (int i = 1; i <= x; i++) {
      if (x % i == 0) v.push_back(i);
    }
    d2[x] = v;
  }
  vector<ll> ans = f(K);
  int n = min((ll)MAX, (ll)ans.size());
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }

  return 0;
}
