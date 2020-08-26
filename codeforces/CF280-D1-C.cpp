#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> adj[100005];
double dp[100005];

void dfs(int u, int p = -1) {
    dp[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] += 0.5 * dp[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << setprecision(16) << dp[1] << endl;

    return 0;
}
