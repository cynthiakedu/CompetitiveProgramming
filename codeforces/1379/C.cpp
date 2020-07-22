#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int T, N, M;
ll cum[100005];
vector<ii> v;

void solve() {
  v.clear();
  cin >> N >> M;

  for (int i = 1; i <= M; i++) {
    ll a, b;
    cin >> a >> b;
    v.push_back(ii(a, b));
  }
  sort(v.begin(), v.end());

  cum[M] = 0;
  for (int i = M - 1; i >= 0; i--)
    cum[i] = cum[i + 1] + v[i].first;

  ll ans = 0;
  if (M >= N) {
    ans = cum[M - N];
  }

  for (int i = 0; i < M; i++) {
    ll a = v[i].first, b = v[i].second;
    int pos =
        (int)(upper_bound(v.begin(), v.end(), ii(b, LLONG_MIN)) - v.begin());
    ll s = cum[pos] + (a <= b ? a : 0);
    ll ct = M - pos + (a <= b ? 1 : 0);
    if (ct <= N) {
      ans = max(ans, s + (ll)(N - ct) * (ll)b);
    }
  }
  cout << ans << endl;
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

// 1
// 2 3
// 5 2
// 4 2
// 3 1
