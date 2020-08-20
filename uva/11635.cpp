#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, hnum, M;
vector<int> H;
vector<ii> adj1[10005];
vector<int> adj2[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) return 0;
        for (int i = 0; i < 10005; i++) {
            adj1[i].clear();
            adj2[i].clear();
        }
        H.clear();
        cin >> hnum;
        for (int i = 1, x; i <= hnum; i++) {
            cin >> x;
            H.push_back(x);
        }
        H.push_back(1);
        H.push_back(N);
        cin >> M;
        for (int i = 1, u, v, t; i <= M; i++) {
            cin >> u >> v >> t;
            adj1[u].push_back({v, t});
            adj1[v].push_back({u, t});
        }

        for (auto h : H) {
            priority_queue<ii, vector<ii>, greater<ii>> pq;
            vector<int> dist(N + 1, -1);
            pq.push({0, h});
            dist[h] = 0;
            while (!pq.empty()) {
                ii p = pq.top();
                pq.pop();
                int d = p.first, u = p.second;
                if (dist[u] < d) continue;
                for (auto v : adj1[u]) {
                    if (dist[v.first] == -1 || dist[v.first] > dist[u] + v.second) {
                        dist[v.first] = dist[u] + v.second;
                        pq.push({dist[v.first], v.first});
                    }
                }
            }
            for (auto h2 : H) {
                if (h2 == h) continue;
                if (dist[h2] <= 600) {
                    adj2[h].push_back(h2);
                }
            }
        }

        queue<int> q;
        vector<int> dist(N + 1, -1);
        q.push(1);
        dist[1] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj2[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        cout << (dist[N] == -1 ? -1 : dist[N] - 1) << endl;
    }

    return 0;
}
