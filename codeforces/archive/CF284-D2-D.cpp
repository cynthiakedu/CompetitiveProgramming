#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, ll>
ll dist[400005];
vector<ii> adj[400005];
int N;
ll arr[200005];

void dfs(int u = 0) {
    for (auto v : adj[u]) {
        dist[v.first] = dist[u] + v.second;
        dfs(v.first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 2; i <= N; i++) cin >> arr[i];

    for (int i = 2; i <= N; i++) {
        int x = i + arr[i], y = i - arr[i];
        if (x > N) {
            adj[0].push_back({i, arr[i]});
        } else {
            adj[N + x].push_back({i, arr[i]});
        }
        if (y <= 0) {
            adj[0].push_back({N + i, arr[i]});
        } else {
            adj[y].push_back({N + i, arr[i]});
        }
    }
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    dfs();

    for (int i = 1; i <= N - 1; i++) {
        ll d = dist[N + i + 1];
        cout << (d == -1 ? -1 : i + d) << endl;
    }

    return 0;
}
