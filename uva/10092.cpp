#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int nk, np;
map<int, int> adj[2000];
int src, sink, mf, f;
vector<int> p;
int total = 0;

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

    while ((cin >> nk) && (cin >> np)) {
        if (!nk && !np) return 0;
        mf = 0;
        total = 0;
        for (int i = 0; i < 2000; i++) adj[i].clear();
        sink = nk + np + 1;
        for (int i = 1, x; i <= nk; i++) {
            cin >> x;
            adj[0][i] = x;
            total += x;
        }
        for (int i = 1, x; i <= np; i++) {
            cin >> x;
            for (int j = 0, y; j < x; j++) {
                cin >> y;
                adj[y][i + nk] = 1;
            }
            adj[i + nk][sink] = 1;
        }

        while (1) {
            vector<int> dist(nk + np + 5, -1);
            p.assign(nk + np + 5, -1);
            queue<int> q;
            f = 0;

            q.push(src);
            dist[src] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (auto v : adj[u]) {
                    if (v.second && dist[v.first] == -1) {
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
        if (mf != total) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            for (int i = 1; i <= nk; i++) {
                vector<int> v;
                for (int j = 1; j <= np; j++) {
                    if (adj[i].count(nk + j) && adj[i][nk + j] == 0) {
                        v.push_back(j);
                    }
                }
                for (int a = 0; a < v.size(); a++) cout << v[a] << (a == v.size() - 1 ? "\n" : " ");
            }
        }
    }

    return 0;
}
