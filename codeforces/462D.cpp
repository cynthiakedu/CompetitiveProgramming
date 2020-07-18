#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
int N, C[100005];
bool visited[100005];
vector<int> adjList[100005];
ll MOD = 1000000007;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
ii visit(int x) {
  visited[x] = true;
  vector<ii> v;
  for (auto y : adjList[x]) {
    if (!visited[y]) {
      ii res = visit(y);
      v.push_back(res);
    }
  }
  if (v.size() == 0) {
    return C[x] ? ii(1, 0) : ii(0, 1);
  }
  ll prod = 1, A = 0;
  for (auto p : v) {
    prod = (prod * ((p.first + p.second) % MOD)) % MOD;
  }

  if (C[x]) return ii(prod, 0);

  for (int i = 0; i < v.size(); i++) {
    ii p = v[i];
    if ((p.first + p.second) % MOD == 0) {
      A = p.first;
      for (int j = 0; j < v.size(); j++) {
        if (j != i) {
          A = (A * ((v[j].first + v[j].second) % MOD));
        }
      }
      return ii(A, prod);
    }
  }

  for (auto p : v) {
    A = (A + (((prod * p.first) % MOD) * inv(p.first + p.second, MOD)) % MOD) %
        MOD;
  }
  return ii(A, prod);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0, p; i < N - 1; i++) {
    cin >> p;
    adjList[p].push_back(i + 1);
    adjList[i + 1].push_back(p);
  }
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  ii ans = visit(0);
  cout << ans.first << endl;

  return 0;
}
