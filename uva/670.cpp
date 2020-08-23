#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
double arr1[105][2], arr2[105][2];
int N, M, L;

int src, sink, mf, f;
map<int, int> adj[500];
vector<int> p;

void augment(int v, int minEdge) {
    if (v == src) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(adj[p[v]][v], minEdge));
        adj[p[v]][v] -= f;
        adj[v][p[v]] += f;
    }
}

double getDist(double a, double b, double c, double d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L;
    for (int l = 0; l < L; l++) {
        if (l != 0) cout << "\n";
        for (int i = 0; i < 500; i++) adj[i].clear();

        cin >> N >> M;
        for (int i = 1; i <= N; i++) cin >> arr1[i][0] >> arr1[i][1];
        for (int i = 1; i <= M; i++) cin >> arr2[i][0] >> arr2[i][1];
        sink = 2 * N + 2 * M + 1;

        for (int i = 1; i <= N - 1; i++) {
            int j = i + 1;
            double d = getDist(arr1[i][0], arr1[i][1], arr1[j][0], arr1[j][1]);

            for (int k = 1; k <= M; k++) {
                double d1 = getDist(arr1[i][0], arr1[i][1], arr2[k][0], arr2[k][1]);
                double d2 = getDist(arr1[j][0], arr1[j][1], arr2[k][0], arr2[k][1]);

                if (d1 + d2 <= 2 * d) {  //i, k, j
                    adj[i][2 * N + k] = 1;
                    adj[2 * N + M + k][N + j] = 1;
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            adj[0][i] = 1;
            adj[i + N][2 * N + 2 * M + 1] = INT_MAX;
        }
        for (int i = 1; i <= M; i++) {
            adj[2 * N + i][2 * N + M + i] = 1;
        }

        while (true) {
            p.assign(2 * N + 2 * M + 5, -1);
            vector<int> dist(2 * N + 2 * M + 5, -1);
            queue<int> q;
            f = 0;

            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (auto v : adj[u]) {
                    if (v.second > 0 && dist[v.first] == -1) {
                        q.push(v.first);
                        dist[v.first] = dist[u] + 1;
                        p[v.first] = u;
                    }
                }
            }
            augment(sink, INT_MAX);
            if (f == 0) break;
            mf += f;
        }

        vector<ii> ans;
        for (int i = 1; i <= N; i++) {
            ans.push_back({(int)arr1[i][0], (int)arr1[i][1]});
            for (auto v : adj[i]) {
                if (v.second == 0) {
                    ans.push_back({(int)arr2[v.first - 2 * N][0], (int)arr2[v.first - 2 * N][1]});
                }
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << (i == ans.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
