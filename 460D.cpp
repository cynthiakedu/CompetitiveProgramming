#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = LLONG_MAX, L, R, K;
vector<ll> ansV;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> L >> R >> K;

  vector<ll> v;
  for (ll i = L; i <= min(L + 7, R); i++) {
    v.push_back(i);
  }
  for (int i = 1; i < (1 << (v.size())); i++) {
    ll res = 0;
    vector<ll> v2;
    for (int j = 0; j < (int)v.size(); j++) {
      if (i & (1 << j)) {
        res ^= v[j];
        v2.push_back(v[j]);
      }
    }
    if (res < ans && v2.size() <= K) {
      ans = res;
      ansV = v2;
    }
  }

  if (K == 3) {
    ll a = floor(log2(L));
    if (R >= pow(2, a + 1) + pow(2, a)) {
      ans = 0;
      ansV =
          vector<ll>{((1ll << (a + 1)) - 1), (1ll << (a + 1)) + (1ll << a) - 1,
                     (1ll << (a + 1)) + (1ll << a)};
    }
  }

  cout << ans << endl;
  cout << ansV.size() << endl;
  for (int i = 0; i < (int)ansV.size(); i++)
    cout << ansV[i] << (i == ansV.size() - 1 ? "\n" : " ");

  return 0;
}
