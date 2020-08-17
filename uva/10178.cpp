#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, E;
ll e, v, c;
map<char, bool> vis;
map<char, vector<char>> adj;
set<char> nodes;

void dfs(char u) {
    if (vis[u]) return;
    vis[u] = true;
    v++;
    for (auto v : adj[u]) {
        e++;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> N) && (cin >> E)) {
        vis.clear();
        adj.clear();
        c = 0;
        for (int i = 0; i < E; i++) {
            char a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            nodes.insert(a);
            nodes.insert(b);
        }
        ll ans = 0;
        for (auto x : nodes) {
            if (vis[x]) continue;
            c++;
            e = 0;
            v = 0;
            dfs(x);
            e /= 2;
            ans += e + 2 - v;
        }
        ans -= (c - 1);
        cout << ans << endl;
    }

    return 0;
}
