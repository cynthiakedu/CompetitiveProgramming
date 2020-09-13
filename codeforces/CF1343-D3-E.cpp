#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int T, N, M, cities[3], dist[3][mxN + 5];
vector<int> adj[mxN + 5];
ll p[mxN + 5], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < mxN + 5; i++) adj[i].clear();
        ans = LLONG_MAX;

        cin >> N >> M;
        for (int i = 0; i < 3; i++) cin >> cities[i];
        for (int i = 1; i <= M; i++) cin >> p[i];
        for (int i = 1, u, v; i <= M; i++) {
            cin >> u >> v;
        }

        for (int i = 0; i < 3; i++) {
            queue<int> q;
            q.push(i);
            dist[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
            }
        }
    }

    return 0;
}
