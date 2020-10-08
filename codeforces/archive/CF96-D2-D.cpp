#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
int N, M;
vector<ii> adj1[1005];
vector<ii> adj2[1005];
ll t[1005], c[1005];
int s, e;
ll dist[1005];

void dij(int u, vector<ii> adj[]) {
    for (int i = 0; i < 1005; i++) dist[i] = LLONG_MAX;
    dist[u] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        ii p = pq.top();
        pq.pop();
        ll d = p.first, u = p.second;
        if (d > dist[u]) continue;
        for (auto v : adj[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> s >> e;
    for (int i = 0, u, v, c; i < M; i++) {
        cin >> u >> v >> c;
        adj1[u].push_back({v, c});
        adj1[v].push_back({u, c});
    }
    for (int i = 1; i <= N; i++) cin >> t[i] >> c[i];

    for (int i = 1; i <= N; i++) {
        dij(i, adj1);
        for (int j = 1; j <= N; j++) {
            if (j == i) continue;
            if (dist[j] <= t[i]) {
                adj2[i].push_back({j, c[i]});
            }
        }
    }

    dij(s, adj2);
    if (dist[e] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[e] << endl;
    }

    return 0;
}
