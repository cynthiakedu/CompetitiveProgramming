#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, M, K;
bool vis[mxN + 5];
vector<int> adj[mxN + 5];
queue<int> q;
int dist[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof dist);
    cin >> N >> M >> K;
    for (int i = 0, x; i < M; i++) {
        cin >> x;
        q.push(s);
        dist[s] = 0;
    }
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (!q.empty()) {
        int u = q.front();
    }
    return 0;
}
