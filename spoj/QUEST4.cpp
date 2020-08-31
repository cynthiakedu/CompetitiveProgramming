#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;

map<int, int> adj[250];
int src, sink, mf, f;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == src) {
        f = minEdge;
        return;
    }
    if (p[v] != -1) {
        augment(p[v], min(minEdge, adj[p[v]][v]));
        adj[p[v]][v] -= f;
        adj[v][p[v]] += f;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 250; i++) adj[i].clear();
        mf = 0;
        cin >> N;
        sink = 241;
        for (int i = 0, x, y; i < N; i++) {
            cin >> x >> y;
            adj[x + 1][121 + y] = 1;
        }
        for (int i = 1; i <= 120; i++) {
            adj[src][i] = 1;
            adj[i + 120][sink] = 1;
        }

        while (1) {
            queue<int> q;
            vector<int> dist(255, -1);
            p.assign(255, -1);
            f = 0;

            q.push(src);
            dist[src] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (adj[u][v.first] > 0 && dist[v.first] == -1) {
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
        cout << mf << endl;
    }

    return 0;
}
