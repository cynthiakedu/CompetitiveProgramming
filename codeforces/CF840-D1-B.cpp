#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3e5;
int N, M, arr[mxN + 5];
vector<ii> adj[mxN + 5];
bool vis[mxN + 5];
int root = -1, s = 0;
vector<int> ans;

int dfs(int u) {
    int ret = 0;
    vis[u] = true;
    for (auto v : adj[u]) {
        if (vis[v.first]) continue;
        if (dfs(v.first) % 2 != arr[v.first]) {
            ans.push_back(v.second);
            ret++;
        }
    }
    return ret % 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s += arr[i];
        if (arr[i] == -1) root = i;
    }

    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    if (root == -1) {
        if (s % 2 == 1) {
            cout << -1 << endl;
            return 0;
        } else {
            root = 1;
        }
    }

    dfs(root);

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << endl;
    }

    return 0;
}
