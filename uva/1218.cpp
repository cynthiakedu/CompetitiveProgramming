#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int dp[10005][3];
vector<int> adj[10005];
int N;

int dfs(int u, int t, int p = -1) {
    if (dp[u][t] != -1) return dp[u][t];
    int& ret = dp[u][t];
    ret = 0;
    bool ok = true;
    if (t == 0) {
        for (int v : adj[u]) {
            int x = dfs(v, 1, u);
            if (x == -1)
                ok = false;
            else
                ret += x;
        }
        if (!ok) ret = INT_MAX;
    } else if (t == 1) {
        int ct = 0, a = -1;
        int s = 0;
        for (int v : adj[u]) {
            int x = dfs(v, 1, u);
            if (x == INT_MAX) {
                ct++;
                a = v;
            }
            s += x;
        }
        ret = INT_MAX;
        if (ct > 1) return ret;
        if (ct == 1) {
            int y = dfs(a, 2, u);
            if (y != -1) {
                ret = (s - (-1)) + y;
            }
            return ret;
        }
        for (int v : adj[u]) {
            int y = dfs(v, 2, u);
            int y0 = dfs(v, 1, u);
            if (y != INT_MAX && y0 != INT_MAX) {
                ret = min(ret, y + (s - y0));
            }
        }
    } else {
        ret = 1;
        for (int v : adj[u]) {
            int x = min(dfs(v, 0, u), dfs(v, 2));
            if (x == INT_MAX)
                ok = false;
            else
                ret += x;
        }
        if (!ok) ret = INT_MAX;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) continue;
        if (N == -1) return 0;

        for (int i = 0, u, v; i < N - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << min(dfs(1, 1), dfs(1, 2)) << endl;
    }

    return 0;
}
