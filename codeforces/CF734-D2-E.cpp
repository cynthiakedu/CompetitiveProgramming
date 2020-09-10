#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N;
vector<int> adj[mxN + 5];
int arr[mxN + 5], p[mxN + 5];
bool vis[mxN + 5];
vector<int> roots;
vector<int> adj2[mxN + 5];

int dp[3][2];

void dfs(int u, int c, int rt) {
    vis[u] = true;
    p[u] = rt;
    for (int v : adj[u]) {
        if (arr[v] != c) {
            adj2[rt].push_back(v);
            continue;
        }
        if (vis[v]) continue;

        dfs(v, c, rt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        roots.push_back(i);
        dfs(i, arr[i], i);
    }

    for (int x : roots) {
        for (int i = 0; i < adj2[x].size(); i++) {
            adj2[x][i] = p[adj2[x][i]];
        }
    }

    dp[0][1] = p[1];

    for (int t = 1; t <= 2; t++) {
        int rt = dp[t - 1][1];
        vector<int> dist(mxN + 5, -1);
        queue<int> q;
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
        for (int x : roots) {
            if (dist[x] > dp[t][0]) {
                dp[t][0] = dist[x];
                dp[t][1] = x;
            }
        }
    }
    cout << (dp[2][0] + 1) / 2 << endl;

    return 0;
}
