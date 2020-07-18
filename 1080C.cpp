#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
int T;
ll N, M, x1, x2, y11, y2, x3, x4, y3, y4;

ii getCt(ll a, ll b, ll c, ll d) { // white, black
  ll total = (b - a + 1) * (d - c + 1);
  if ((b - a + 1) % 2 == 0 || (d - c + 1) % 2 == 0) {
    return ii(total / 2, total / 2);
  } else {
    if ((a + c) % 2 == 0) {
      return ii(total / 2 + 1, total / 2);
    } else {
      return ii(total / 2, total / 2 + 1);
    }
  }
}

void solve() {
  cin >> N >> M;
  cin >> x1 >> y11 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;

  ll black = 0;
  ii p = getCt(1ll, M, 1ll, N);
  ii p1 = getCt(x1, x2, y11, y2);
  ii p2 = getCt(x3, x4, y3, y4);
  black = p.second - p1.second + p2.first;

  ll a = max(x1, x3);
  ll b = min(x2, x4);
  ll c = max(y11, y3);
  ll d = min(y2, y4);
  if (b >= a && d >= c) {
    ii p3 = getCt(a, b, c, d);
    black += p3.second;
  }
  cout << N * M - black << " " << black << endl;
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
