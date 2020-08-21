#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, B, D;
map<int, ll> adj[250];
int src, sink;
ll mf, f;
vector<int> p;

void augment(int v, ll minEdge) {
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

    while (cin >> N) {
        for (int i = 0; i < 250; i++) adj[i].clear();
        src = 0, sink = 2 * N + 1;
        mf = 0;

        for (int i = 1, x; i <= N; i++) {
            cin >> x;
            adj[i][i + N] = x;
        }
        cin >> M;
        for (int i = 0, u, v, c; i < M; i++) {
            cin >> u >> v >> c;
            adj[u + N][v] += c;
        }
        cin >> B >> D;
        for (int i = 0, x; i < B; i++) {
            cin >> x;
            adj[0][x] = LLONG_MAX;
        }
        for (int i = 0, x; i < D; i++) {
            cin >> x;
            adj[x + N][2 * N + 1] = LLONG_MAX;
        }

        while (1) {
            f = 0;
            vector<int> dist(2 * N + 5, -1);
            p.assign(2 * N + 5, -1);
            queue<int> q;

            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (auto v : adj[u]) {
                    if (v.second > 0 && dist[v.first] == -1) {
                        q.push(v.first);
                        dist[v.first] = dist[u] + 1;
                        p[v.first] = u;
                    }
                }
            }
            augment(sink, LLONG_MAX);
            if (f == 0) break;
            mf += f;
        }
        cout << mf << endl;
    }

    return 0;
}
