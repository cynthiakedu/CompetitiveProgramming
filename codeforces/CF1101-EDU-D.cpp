#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
bool vis[mxN + 5];
vector<int> primes[mxN + 5];

int N, vals[mxN + 5];
vector<int> adj[mxN + 5];
map<int, int> res[mxN + 5];
map<int, int> res2[mxN + 5];
int ans = 0;

void dfs(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    for (int x : primes[vals[u]]) {
        vector<int> v1;
        for (int v : adj[u]) {
            if (v == p) continue;
            v1.push_back(res2[v][x]);
        }
        sort(v1.begin(), v1.end());
        int n = (int)v1.size();
        res[u][x] = 1;
        if (n >= 1) res[u][x] += v1[n - 1];
        if (n >= 2) res[u][x] += v1[n - 2];

        res2[u][x] = 1;
        if (n >= 1) res2[u][x] += v1[n - 1];
        ans = max(ans, res[u][x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < mxN + 5; i++) {
        if (vis[i]) continue;
        for (int j = i; j < mxN + 5; j += i) {
            vis[j] = true;
            primes[j].push_back(i);
        }
    }

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> vals[i];

    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << ans << endl;

    return 0;
}
