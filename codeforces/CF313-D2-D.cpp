#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K;
ll adj[305][305];
ll dp[305][305];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(adj, -1, sizeof adj);

    cin >> N >> M >> K;
    for (int i = 0, l, r, c; i < M; i++) {
        cin >> l >> r >> c;
        if (adj[l][r] == -1 || c < adj[l][r]) {
            adj[l][r] = c;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (adj[i - 1][j] != -1) {
                if (adj[i][j] == -1 || adj[i - 1][j] < adj[i][j]) {
                    adj[i][j] = adj[i - 1][j];
                }
            }
        }
    }

    for (int i = N + 1; i >= 1; i--) {
        for (int j = 0; j <= N; j++) {
            if (i == N + 1) {
                dp[i][j] = (j == 0 ? 0 : LLONG_MAX);
                continue;
            }
            ll& ret = dp[i][j];
            ret = LLONG_MAX;
            ret = dp[i + 1][j];
            for (int k = i; k <= N; k++) {
                if (adj[i][k] == -1) continue;
                if (k - i + 1 >= j) {
                    ret = min(ret, adj[i][k]);
                }
                if (dp[k + 1][j - (k - i + 1)] != LLONG_MAX) {
                    ret = min(ret, dp[k + 1][j - (k - i + 1)] + adj[i][k]);
                }
            }
        }
    }
    if (dp[1][K] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[1][K] << endl;
    return 0;
}
