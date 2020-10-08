#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 2e5;
int N, dp[mxN + 5][4];
vector<int> adj[mxN + 5];

int dfs(int u, int x, int p = -1) {
    if (dp[u][x] != -1) return dp[u][x];
    int& ret = dp[u][x];
    ret = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        ret += min(1 + dfs(v, 1, u), dfs(v, x == 3 ? 3 : x + 1, u));
    }
    if (x == 3) {
        int tmp = INT_MAX;
        for (int v : adj[u]) {
            if (v == p) continue;
            int t = min(1 + dfs(v, 1, u), dfs(v, 3, u));
            tmp = min(tmp, ret - t + 1 + dfs(v, 1, u));
        }
        if (tmp == INT_MAX) tmp = 1;
        ret = tmp;
    }
    if (debug) cout << "dp " << u << " " << x << " " << ret << endl;
    return ret;
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
// 6
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
