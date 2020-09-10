#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 1e5;
int N;
vector<int> adj[mxN + 5];

ll dp[mxN + 5][2][2], diff[mxN + 5];

ll dfs1(int u, int p, int x, int parent = -1) {
    ll& ret = dp[u][p][x];

    if (ret != -1) return ret;

    ll temp = 1, ct = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        ll a = dfs1(v, x ? 1 - p : p, 0, u);
        ll b = dfs1(v, x ? 1 - p : p, 1, u);
        temp = (temp * (a + b)) % MOD;
        ct++;
    }

    if (!ct) {
        if (x) {
            ret = p ? 1 : 0;
        } else {
            ret = p ? 0 : 1;
        }
    } else {
        ret = temp;
    }
    return ret;
}
void dfs2(int u, int parent = -1) {
    ll oddS = 1, evenS = 1, ct = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        ll a = (dfs1(v, 0, 0, u) + dfs1(v, 0, 1, u)) % MOD;
        ll b = (dfs1(v, 1, 0, u) + dfs1(v, 1, 1, u)) % MOD;
        ct++;
        evenS = (evenS * a) % MOD;
        oddS = (oddS * b) % MOD;
    }
    for (int v : adj[u]) {
        if (v == parent) continue;
        ll a = (dfs1(v, 0, 0, u) + dfs1(v, 0, 1, u)) % MOD;
        ll b = (dfs1(v, 1, 0, u) + dfs1(v, 1, 1, u)) % MOD;
        diff[v] = diff[u];
        diff[v] = (diff[v] + (((ct > 1 ? evenS : 0) / a) * ((dfs1(v, 0, 0, u) - dfs1(v, 1, 0, u) + MOD) % MOD)) % MOD) % MOD;
        diff[v] = (diff[v] + (dfs1(v, 0, 1, u) * ((((ct > 1 ? oddS : 0) / b) - (evenS / a) + MOD)) % MOD) % MOD) % MOD;
    }
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs2(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> N;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    diff[1] = dfs1(1, 1, 0) + dfs1(1, 0, 0);
    dfs2(1);

    ll ans = 0;
    for (int i = 1; i <= N; i++) ans = (ans + diff[i]) % MOD;

    cout << ans << endl;

    return 0;
}
