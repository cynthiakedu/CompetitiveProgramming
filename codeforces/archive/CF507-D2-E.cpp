#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define pi pair<ii, ii>
const int mxN = 1e5;
int N, M;
vector<ii> adj[mxN + 5];
int edge[mxN + 5][2], arr[mxN + 5], selected[mxN + 5];
int dist[mxN + 5], mn0[mxN + 5];
int pEdge[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof dist);
    memset(mn0, -1, sizeof mn0);

    cin >> N >> M;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v >> arr[i];
        edge[i][0] = u;
        edge[i][1] = v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[1] = 0;
    pq.push({{0, 0}, {1, -1}});

    while (!pq.empty()) {
        pi p = pq.top();
        pq.pop();
        int u = p.second.first;
        int d = p.first.first, num0 = p.first.second;
        pEdge[u] = p.second.second;

        if (u != 1 && (d > dist[u] || num0 > mn0[u])) continue;
        if (u == N) break;

        for (ii v : adj[u]) {
            int newDist = dist[u] + 1;
            int newNum0 = num0 + (1 - arr[v.second]);
            if (dist[v.first] == -1 || dist[v.first] > newDist) {
                dist[v.first] = newDist;
                mn0[v.first] = newNum0;
                pq.push({{dist[v.first], mn0[v.first]}, {v.first, v.second}});
            } else if (dist[v.first] == newDist) {
                if (mn0[v.first] == -1 || mn0[v.first] > newNum0) {
                    mn0[v.first] = newNum0;
                    pq.push({{dist[v.first], mn0[v.first]}, {v.first, v.second}});
                }
            }
        }
    }

    int x = N;
    while (x != 1) {
        int idx = pEdge[x];
        selected[idx] = 1;
        if (edge[idx][0] != x) {
            x = edge[idx][0];
        } else {
            x = edge[idx][1];
        }
    }

    vector<pair<ii, int>> ans;
    for (int i = 1; i <= M; i++) {
        if (selected[i]) {
            if (arr[i] == 0) {
                ans.push_back({{edge[i][0], edge[i][1]}, 1});
            }
        } else {
            if (arr[i] == 1) {
                ans.push_back({{edge[i][0], edge[i][1]}, 0});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }

    return 0;
}
