#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int arr[mxN + 5];
vector<int> adj[mxN + 5];
ll dp[2][35][mxN + 5], ans[35][mxN + 5];
ll ans2 = 0;

void dfs(int u, int idx, int p = -1) {
    int dig = (arr[u] >> idx) & (1);
    ll sEven = 0, sOdd = 0, sub1 = 0, sEvenOddSub = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, idx, u);
        sEven += dp[0][idx][v];
        sOdd += dp[1][idx][v];
        sub1 += dp[0][idx][v] * dp[0][idx][v] + dp[1][idx][v] * dp[1][idx][v];
        sEvenOddSub += dp[0][idx][v] * dp[1][idx][v];
        dp[(dig + 0) % 2][idx][u] += dp[0][idx][v];
        dp[(dig + 1) % 2][idx][u] += dp[1][idx][v];
    }
    if (dig == 1) {
        ans[idx][u] = (sEven * sEven + sOdd * sOdd - sub1) / 2 + dp[1][idx][u];
    } else {
        ans[idx][u] = sEven * sOdd - sEvenOddSub + dp[1][idx][u];
    }
    dp[dig][idx][u]++;
    if (dig == 1) ans[idx][u] += 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < 21; i++) {
        dfs(1, i);
        ll temp = 0;
        for (int j = 1; j <= N; j++) {
            temp += ans[i][j];
        }
        ans2 += temp * (1LL << i);
    }
    cout << ans2 << endl;

    return 0;
}
