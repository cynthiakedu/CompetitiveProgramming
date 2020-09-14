#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 500000;
int Q, N, K;
vector<ii> adj[mxN + 5];
ll dp[mxN + 5][2];

void dfs(int u, int p = -1) {
    dp[u][0] = 0, dp[u][1] = 0;
    int sum = 0;
    vector<int> v;
    for (auto &it : adj[u]) {
        if (it.first == p)
            continue;
        dfs(it.first, u);
        sum += dp[it.first][0];
        int gain = dp[it.first][1] + it.second - dp[it.first][0];
        if (gain > 0)
            v.push_back(gain);
    }
    sort(v.rbegin(), v.rend());
    int sz = min(K - 1, (int)v.size());
    for (int i = 0; i < sz; i++)
        sum += v[i];
    dp[u][1] = sum;
    dp[u][0] = sum;
    if (sz < v.size())
        dp[u][0] += v[sz];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            adj[i].clear();
        for (int i = 1; i <= N - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dfs(1, 0);
        cout << dp[1][0] << endl;
    }

    return 0;
}