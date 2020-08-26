#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, M;
vector<int> adj[mxN + 5];
int dist[mxN + 5], ct[mxN + 5];
int diam[3][2];
bool isCity[mxN + 5];

void dfs(int u, int p = -1) {  //clear ct, dist
    for (auto v : adj[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u);
        ct[u] += ct[v] + ((ct[v] || isCity[v]) ? 1 : 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0, x; i < M; i++) {
        cin >> x;
        isCity[x] = true;
        diam[0][0] = x;
    }

    for (int i = 0; i < 3; i++) diam[i][1] = INT_MIN;
    for (int t = 1; t <= 2; t++) {
        memset(dist, 0, sizeof dist);
        memset(ct, 0, sizeof ct);
        dfs(diam[t - 1][0]);
        for (int i = 1; i <= N; i++) {
            if (!isCity[i]) continue;
            if (dist[i] > diam[t][1]) {
                diam[t][1] = dist[i];
                diam[t][0] = i;
            }
        }
    }

    cout << min(diam[1][0], diam[2][0]) << endl;
    cout << 2 * (ct[diam[1][0]]) - diam[2][1] << endl;

    return 0;
}
