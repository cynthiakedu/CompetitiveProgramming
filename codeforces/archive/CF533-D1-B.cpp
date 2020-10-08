#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N;
ll val[mxN + 5];
vector<int> adj[mxN + 5];
ll dp[mxN + 5][2];

ll dfs(int u, int p) {
    if (dp[u][p] != -1) return dp[u][p];
    ll mxNeg = LLONG_MIN, totalEven = 0;
    ll changeEven = 0, ct = 0, mnChange = LLONG_MAX;
    for (int v : adj[u]) {
        ll a = dfs(v, 0), b = dfs(v, 1);
        totalEven += a;
        if (b - a >= 0) {
            ct++;
            changeEven += b - a;
            mnChange = min(b - a, mnChange);
        } else {
            mxNeg = max(mxNeg, a - b);
        }
    };

    ll sOdd = totalEven + (ct ? (changeEven - (ct % 2 == 0 ? mnChange : 0)) : mxNeg);
    ll sEven = totalEven + changeEven - (ct % 2 == 1 ? mnChange : 0);

    dp[u][p] = 0;
    if (p == 0) {
        dp[u][p] = sEven;
    } else {
        dp[u][p] = sEven + val[u];
        if (sOdd != -1) {
            dp[u][p] = max(dp[u][p], sOdd);
        }
    }
    return dp[u][p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        ll x;
        cin >> a >> x;
        val[i] = x;
        if (a != -1) {
            adj[a].push_back(i);
        }
    }
    cout << max(dfs(1, 0), dfs(1, 1)) << endl;

    return 0;
}
