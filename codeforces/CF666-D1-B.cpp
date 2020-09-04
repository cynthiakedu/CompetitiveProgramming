#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int dist[5005][5005], N, M;
vector<int> adj[5005];
vector<ii> in[5005], out[5005];
int a, b, c, d, ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dist, -1, sizeof dist);

    cin >> N >> M;
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);  //FORGOT
                }
            }
        }
        for (int j = 1; j <= N; j++) {
            if (j == i) continue;
            if (dist[i][j] == -1) continue;

            out[i].push_back({dist[i][j], j});
            in[j].push_back({dist[i][j], i});
        }
    }

    for (int i = 1; i <= N; i++) {
        sort(in[i].begin(), in[i].end());
        reverse(in[i].begin(), in[i].end());
        sort(out[i].begin(), out[i].end());
        reverse(out[i].begin(), out[i].end());
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (dist[i][j] == -1) continue;

            int n1 = min(4, (int)in[i].size());
            int n2 = min(4, (int)out[j].size());

            for (int i1 = 0; i1 < n1; i1++) {
                for (int j1 = 0; j1 < n2; j1++) {
                    int idi = in[i][i1].second, idj = out[j][j1].second;
                    int d1 = in[i][i1].first, d2 = out[j][j1].first;
                    if (idi == idj) continue;
                    if (idi == j || idj == i) continue;
                    int temp = d1 + d2 + dist[i][j];
                    if (temp > ans) {
                        a = idi;
                        b = i;
                        c = j;
                        d = idj;
                        ans = temp;
                    }
                }
            }
        }
    }
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
