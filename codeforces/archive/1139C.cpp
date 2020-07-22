#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
bool vis[100005];
#define MOD 1000000007
int N, K;
vector<ii> adjList[100005];
ll ans = 0;

ll pmod(ll a, ll b) {
  if (b == 0)
    return 1;
  ll x = pmod(a, b / 2);
  return (((x * x) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

ll visit(int x) {
  vis[x] = true;
  ll ct = 0;
  for (auto p : adjList[x]) {
    if (!vis[p.first]) {
      ll c = visit(p.first);
      if (p.second) {
        ans = (ans + pmod(c, K)) % MOD;
      } else {
        ct += c;
      }
    }
  }
  return ct + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 0, u, v, x; i < N - 1; i++) {
    cin >> u >> v >> x;
    adjList[u].push_back(ii(v, x));
    adjList[v].push_back(ii(u, x));
  }

  ll ct = visit(1);
  ans = (ans + pmod(ct, K)) % MOD;
  cout << (pmod(N, K) + MOD - ans) % MOD << endl;

  return 0;
}
