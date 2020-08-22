#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int K, N;
vector<int> adj[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    for (int i = 0, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(K + 1, -1);
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        ii p = pq.top();
        pq.pop();
        int u = p.second, d = p.first;
        if (d > dist[u]) continue;

        for (int v : adj[u]) {
            int newd, d1 = abs(u - v);
            if (u < v) {
                newd = 10 * d1 * ((d + 10 * d1 - 1) / (10 * d1)) + 5 * d1;
            } else {
                newd = max(0, (d - 5 * d1 + 10 * d1 - 1) / (10 * d1)) * 10 * d1 + 5 * d1 + 5 * d1;
            }

            if (dist[v] == -1 || newd < dist[v]) {
                dist[v] = newd;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[K] << endl;

    return 0;
}
