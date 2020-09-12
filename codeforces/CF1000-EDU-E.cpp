#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3e5;
int N, M, edge[mxN + 5][2];
vector<ii> adj[mxN + 5];
vector<int> adj2[mxN + 5];
int dp[3][2];
int dfs_low[mxN + 5], dfs_num[mxN + 5], dfsCounter = 0;
bool isBridge[mxN + 5];

void dfs(int u, int p = -1) {
    dfs_low[u] = dfs_num[u] = dfsCounter++;
    for (auto v : adj[u]) {
        if (dfs_num[v.first] == -1) {
            dfs(v.first, u);
            if (dfs_low[v.first] > dfs_num[u]) {
                isBridge[v.second] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        } else if (v.first != p) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
        }
    }
}

int p[mxN + 5], r[mxN + 5];
int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) r[x]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dfs_num, -1, sizeof dfs_num);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        edge[i][0] = u;
        edge[i][1] = v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    dfs(1);

    for (int i = 1; i <= M; i++) {
        if (!isBridge[i]) {
            unionSet(edge[i][0], edge[i][1]);
        }
    }

    for (int i = 1; i <= N; i++) {
        int rt = findSet(i);
        for (auto v : adj[i]) {
            int u = v.first;
            if (findSet(u) == rt) continue;
            adj2[rt].push_back(findSet(u));
        }
    }

    dp[0][0] = findSet(1);

    for (int t = 1; t <= 2; t++) {
        int rt = dp[t - 1][0];
        queue<int> q;
        vector<int> dist(N + 1, -1);
        q.push(rt);
        dist[rt] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj2[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (dist[findSet(i)] > dp[t][1]) {
                dp[t][1] = dist[findSet(i)];
                dp[t][0] = findSet(i);
            }
        }
    }

    cout << dp[2][1] << "\n";

    return 0;
}
