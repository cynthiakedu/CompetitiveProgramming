#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int dp[2][100005];
vector<int> adj[100005];

int dfs(int u, int need = 0, int p = -1) {
    if (dp[need][u] != -1) return dp[need][u];
    int ct1 = 1, ct2 = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        ct1 += dfs(v, 0, u);
    }
    if (!need) {
        for (auto v : adj[u]) {
            if (v == p) continue;
            ct2 += dfs(v, 1, u);
        }
        ct1 = min(ct1, ct2);
    }
    return dp[need][u] = ct1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> N;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(1, 0) << endl;
    return 0;
}
