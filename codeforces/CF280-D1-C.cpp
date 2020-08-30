#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> adj[100005];
double dp[100005];
int ct[100005];
double ans;

void dfs(int u, int c = 0, int p = -1) {
    dp[u] = 1;
    ct[u] = 1;
    ans += 1.0 / (c + 1);
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, c + 1, u);
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

    dfs(1);
    cout << setprecision(16) << ans << endl;

    return 0;
}
