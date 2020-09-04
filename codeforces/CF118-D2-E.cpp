#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, M;
vector<int> adj[mxN + 5];

int p[mxN + 5], low[mxN + 5], num[mxN + 5];
int numCounter = 0;

bool ok = true;
vector<ii> ans;

void dfs(int u) {
    low[u] = num[u] = numCounter++;
    for (int v : adj[u]) {
        if (num[v] == -1) {
            p[v] = u;
            dfs(v);
            if (low[v] > num[u]) ok = false;
            low[u] = min(low[u], low[v]);
            ans.push_back({u, v});
        } else if (v != p[u]) {
            low[u] = min(low[u], num[v]);
            if (num[v] < num[u]) {
                ans.push_back({u, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(num, -1, sizeof num);
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if (!ok) {
        cout << 0 << endl;
    } else {
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
