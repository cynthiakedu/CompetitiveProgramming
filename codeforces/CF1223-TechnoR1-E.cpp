#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 5e5;
int Q, N, K;
vector<ii> adj[mxN + 5];
ll dp[mxN + 5][2];

void dfs(int u, int p = -1) {
    dp[u][0] = dp[u][1] = 0;
    vector<ll> changes;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        dfs(v.first, u);
        dp[u][0] += dp[v.first][0];
        changes.push_back(dp[v.first][1] + v.second - dp[v.first][0]);
    }
    sort(changes.begin(), changes.end(), greater<>());

    for (int i = 0; i < min((int)changes.size(), K); i++) {
        dp[u][0] += max(0LL, changes[i]);
    }
    dp[u][1] = dp[u][0];
    if ((int)changes.size() >= K) dp[u][1] -= max(0LL, changes[K - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> N >> K;
        for (int i = 0; i <= N; i++) adj[i].clear();

        for (int i = 0, u, v; i < N - 1; i++) {
            ll w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dfs(1);
        cout << dp[1][0] << "\n";
    }

    return 0;
}