#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<ii> adj[100005];
int N;
vector<ll> dist[100005];
ll saved = 0;
ll S = 0;

void dfs(int u, int p = -1, ll d = 0) {
    saved = max(saved, d);
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        dfs(v.first, u, d + v.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0, x, y, w; i < N - 1; i++) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        S += 2 * w;
    }

    dfs(1);
    cout << S - saved << endl;

    return 0;
}
