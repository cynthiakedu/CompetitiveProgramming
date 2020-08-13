#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int T, n, m, s, t, p;
vector<ii> adj[10005];

bool isPossible(int x) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    vector<ll> dist(n + 1, 0);
    dist[s] = 0;
    while (!pq.empty()) {
        ii p1 = pq.top();
        pq.pop();
        int d = p1.first, u = p1.second;
        if (dist[u] < d) continue;

        for (auto v : adj[u]) {
            if (v.second > x) continue;
            if (dist[v.first] != -1 && dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return (dist[t] != -1) && dist[t] < p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t1 = 0; t1 < T; t1++) {
        for (int i = 0; i < 10005; i++) adj[i].clear();

        cin >> n >> m >> s >> t >> p;
        for (int i = 0, u, v, c; i < m; i++) {
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
        }
        int l = 0, r = 100001;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (isPossible(m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (!isPossible(l)) {
            cout << -1 << endl;
        } else {
            cout << l << endl;
        }
    }

    return 0;
}
