#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, ll>
const int mxN = 1e6;
int N, M, start;
vector<ii> adj[mxN + 5];

int dfs_num[mxN + 5], dfs_low[mxN + 5], visited[mxN + 5];
int dfsNumCtr;
vector<int> S;

ll dist[mxN + 5], inDeg[mxN + 5], mxSelf[mxN + 5];

int p[mxN + 5];
ll ans = 0;

void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumCtr++;
    S.push_back(u);
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (dfs_num[v.first] == -1) {
            dfs(v.first);
        }
        if (visited[v.first]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) {
        p[u] = u;
        while (true) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            if (u != v) {
                p[v] = u;
                adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
                adj[v].clear();
            }
            if (u == v) break;
        }
    }
}

ll getMax(ll num) {
    if (num == 0) return 0;
    ll tmp = max(1LL, (ll)floor(sqrt(2 * num)) - 2);
    while (tmp * (tmp + 1) <= 2 * num) {
        tmp++;
    }
    tmp--;

    ll ret = num * (tmp + 1);
    ret -= (tmp + 2) * (tmp + 1) * (tmp) / 6;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dfs_num, -1, sizeof dfs_num);
    cin >> N >> M;
    for (int i = 0, x, y, w; i < M; i++) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    cin >> start;

    dfs(start);

    for (int i = 1; i <= N; i++) {
        if (dfs_num[i] == -1) continue;
        for (auto v : adj[i]) {
            if (p[v.first] == i) {
                mxSelf[i] += getMax(v.second);
            } else {
                inDeg[p[v.first]]++;
            }
        }
    }

    queue<int> q;
    q.push(p[start]);
    dist[p[start]] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        dist[u] += mxSelf[u];

        ans = max(ans, dist[u]);
        for (auto v : adj[u]) {
            int node = p[v.first];
            if (node == u) continue;
            inDeg[node]--;
            dist[node] = max(dist[node], dist[u] + v.second);
            if (inDeg[node] == 0) q.push(node);
        }
    }
    cout << ans << endl;

    return 0;
}
