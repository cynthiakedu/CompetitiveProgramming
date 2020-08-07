#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int testCt;
int N, M, S, T;
vector<ii> adj[20005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> testCt;
    for (int t = 0; t < testCt; t++) {
        for (int i = 0; i < 20005; i++) adj[i].clear();
        cin >> N >> M >> S >> T;
        for (int i = 0, u, v, w; i < M; i++) {
            cin >> u >> v >> w;
            adj[u].push_back(ii(v, w));
            adj[v].push_back(ii(u, w));
        }
        vector<int> dist(N + 1, -1);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push(ii(0, S)), dist[S] = 0;

        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int u = front.second, d = front.first;
            // cout << "vis " << u << " " << d << endl;
            if (d > dist[u]) continue;
            for (auto v : adj[u]) {
                if (dist[v.first] == -1 || dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
        cout << "Case #" << t + 1 << ": " << (dist[T] == -1 ? "unreachable" : to_string(dist[T])) << endl;
    }

    return 0;
}