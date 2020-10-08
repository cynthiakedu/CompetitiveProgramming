#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> adj[100005];
int init[100005], target[100005];
int ct = 0;
vector<int> ans;

void dfs(int u, int p = -1, int e = 0, int o = 0, int dist = 0) {
    if (dist % 2 == 0 && abs(target[u] - init[u]) % 2 != e % 2) {
        ans.push_back(u);
        e++;
    }
    if (dist % 2 == 1 && abs(target[u] - init[u]) % 2 != o % 2) {
        ans.push_back(u);
        o++;
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, e, o, dist + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) cin >> init[i];
    for (int i = 1; i <= N; i++) cin >> target[i];

    dfs(1);

    cout << ans.size() << endl;
    for (int x : ans) cout << x << endl;

    return 0;
}
