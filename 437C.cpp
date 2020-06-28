#include <bits/stdc++.h>
using namespace std;
int N, M, v[1005];
vector<int> adj[1005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  int ans = 0;
  for (int i = 1; i <= N; i++) cin >> v[i];
  for (int i = 0, a, b; i < M; i++) {
    cin >> a >> b;
    ans += min(v[a], v[b]);
  }
  cout << ans << endl;
  return 0;
}
