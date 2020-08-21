#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
double s, v;
double L[205][2], R[205][2];
map<int, int> adj[205];
int f, mf, src, sink;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == src) {
        f = minEdge;
        return;
    }
    if (p[v] != -1) {
        augment(p[v], min(minEdge, adj[p[v]][v]));
        adj[p[v]][v] -= minEdge;
        adj[v][p[v]] += minEdge;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> N)) {
        for (int i = 0; i < 205; i++) adj[i].clear();
        mf = 0;

        cin >> M >> s >> v;
        src = 0, sink = N + M + 1;
        for (int i = 1; i <= N; i++) cin >> L[i][0] >> L[i][1];
        for (int i = 1; i <= M; i++) cin >> R[i][0] >> R[i][1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                double dx = L[i][0] - R[j][0];
                double dy = L[i][1] - R[j][1];
                if ((s * v) * (s * v) >= dx * dx + dy * dy) {
                    adj[i][j + N] = 1;
                }
            }
            adj[0][i] = 1;
        }
        for (int j = 1; j <= M; j++) adj[j + N][N + M + 1] = 1;

        while (1) {
            vector<int> dist(N + M + 5, -1);
            p.assign(N + M + 5, -1);
            queue<int> q;
            f = 0;

            q.push(src);
            dist[src] = 0;

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
            augment(sink, INT_MAX);
            if (f == 0) break;
            mf += f;
        }
        cout << N - mf << endl;
    }

    return 0;
}
