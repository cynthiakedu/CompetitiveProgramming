#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3e5;
int N, K, D;
int police[mxN + 5], edges[mxN + 5][2], colors[mxN + 5];
vector<ii> adj[mxN + 5];
vector<int> ans;

void dfs(int u, int color, int dist = 0) {
    colors[u] = color;
    if (dist == D) return;

    for (auto v : adj[u]) {
        if (colors[v.first] != -1) continue;
        dfs(v.first, color, dist + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(colors, -1, sizeof colors);
    cin >> N >> K >> D;
    for (int i = 1, p; i <= K; i++) {
        cin >> police[i];
    }
    for (int i = 1, a, b; i <= N - 1; i++) {
        cin >> a >> b;
        edges[i][0] = a;
        edges[i][1] = b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (int i = 1; i <= K; i++) {
        dfs(police[i], police[i]);
    }
    for (int i = 1; i <= N - 1; i++) {
        int a = edges[i][0], b = edges[i][1];
        if (colors[a] != colors[b]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");

    return 0;
}
