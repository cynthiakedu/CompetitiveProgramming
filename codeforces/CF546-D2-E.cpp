#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, a[105], b[105], ans[105][105];
map<int, int> adj[255];
int src, sink, mf, f;
int s1, s2;
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

    cin >> N >> M;
    sink = 2 * N + 1;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        adj[src][i] = a[i];
        s1 += a[i];
        adj[i][i + N] = INT_MAX;
    }
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
        adj[i + N][sink] = b[i];
        s2 += b[i];
    }

    if (s1 != s2) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u][v + N] = INT_MAX;
        adj[v][u + N] = INT_MAX;
    }

    while (true) {
        p.assign(2 * N + 5, -1);
        vector<int> dist(2 * N + 5, -1);
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

    if (mf != s1) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        for (auto v : adj[i]) {
            if (v.first > N) {
                ans[i][v.first - N] = INT_MAX - v.second;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j] << (j == N ? "\n" : " ");
        }
    }

    return 0;
}
