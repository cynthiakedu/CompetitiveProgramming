#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> adj[100005];

double dfs(int u, int p = -1) {
    double ct = 0, s = 0;

    for (auto v : adj[u]) {
        if (p == v) continue;
        double d = dfs(v, u);
        ct++;
        s += d;
    }
    if (ct == 0) return 0.0;
    return 1 + (1.0 / ct) * s;
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
    double ans = dfs(1);
    cout << setprecision(16) << ans << endl;

    return 0;
}
