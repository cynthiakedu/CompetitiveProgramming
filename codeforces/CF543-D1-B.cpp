#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3000;
int N, M, s1, t1, l1, s2, t2, l2;
vector<int> adj[mxN + 5];
int dist[mxN + 5][mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof dist);

    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

    for (int i = 1; i <= N; i++) {
        queue<int> q;
        dist[i][i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int t = 0; t < 2; t++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                if (dist[a][b] == -1) continue;
                if (dist[s1][a] == -1 || dist[b][t1] == -1) continue;
                if (dist[s2][a] == -1 || dist[b][t2] == -1) continue;
                if (dist[s1][a] + dist[a][b] + dist[b][t1] > l1) continue;
                if (dist[s2][a] + dist[a][b] + dist[b][t2] > l2) continue;
                int tmp = dist[s1][a] + dist[b][t1];
                tmp += dist[s2][a] + dist[b][t2];
                tmp += dist[a][b];
                ans = min(ans, tmp);
            }
        }
        swap(s2, t2);
    }

    if (dist[s1][t1] != -1 && dist[s1][t1] <= l1) {
        if (dist[s1][t2] != -1 && dist[s2][t2] <= l2) {
            int tmp = dist[s1][t1] + dist[s2][t2];
            ans = min(ans, tmp);
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << M - ans << endl;
    return 0;
}
