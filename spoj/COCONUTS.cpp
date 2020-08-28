#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
map<int, int> adj[305];
int src, sink, mf, f;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == src) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, adj[p[v]][v]));
        adj[p[v]][v] -= f;
        adj[v][p[v]] += f;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> N) && (cin >> M)) {
        if (!N && !M) return 0;
        for (int i = 0; i < 305; i++) adj[i].clear();
        mf = 0;

        sink = N + 1;

        for (int i = 1, x; i <= N; i++) {
            cin >> x;
            if (x) {
                adj[0][i] = 1;
            } else {
                adj[i][sink] = 1;
            }
        }
        for (int i = 0, u, v; i < M; i++) {
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        while (1) {
            vector<int> dist(N + 5, -1);
            p.assign(N + 5, -1);
            f = 0;
            queue<int> q;

            q.push(src);
            dist[src] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (auto v : adj[u]) {
                    if (v.second && dist[v.first] == -1) {
                        dist[v.first] = dist[u] + 1;
                        p[v.first] = u;
                        q.push(v.first);
                    }
                }
            }
            augment(sink, INT_MAX);
            if (f == 0) break;
            mf += f;
        }
        cout << mf << "\n";
    }

    return 0;
}
