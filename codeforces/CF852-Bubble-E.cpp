#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 1e5;
ll dp[mxN + 5][2][2], diff[mxN + 5];
ll dp2[mxN + 5][2][2];
vector<int> adj[mxN + 5];

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

ll dfs2(int u, int parent = -1) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < mxN + 5; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    return 0;
}
