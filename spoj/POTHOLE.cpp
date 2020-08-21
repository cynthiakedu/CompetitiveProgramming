#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
map<int, int> adj[205];
int mf, f, src, sink, T;
int N;
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
        mf = 0;
        for (int i = 0; i < 205; i++) adj[i].clear();

        cin >> N;
        src = 1, sink = N;
        for (int i = 1, x; i < N; i++) {
            cin >> x;
            for (int j = 1, y; j <= x; j++) {
                cin >> y;
                adj[i][y] = (i == 1 || y == N) ? 1 : INT_MAX;
            }
        }
        while (true) {
            f = 0;
            vector<int> dist(N + 1, -1);
            queue<int> q;
            p.assign(N + 1, -1);
            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (auto v : adj[u]) {
                    if (v.second > 0 && dist[v.first] == -1) {
                        dist[v.first] = dist[u] + 1;
                        q.push(v.first);
                        p[v.first] = u;
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
