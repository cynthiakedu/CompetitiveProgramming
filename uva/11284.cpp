#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define EPS 10e-9
int T, N, M, P, p1[15];
double adj[55][55];
double p2[15];
double dp[(1 << 13)][55];

double solve(int state, int last) {
    if (dp[state][last] != (double)INT_MIN) return dp[state][last];
    double ret = -adj[last][0];
    for (int i = P; i >= 1; i--) {
        if (state & (1 << (i - 1))) {
            ret = max(ret, -adj[last][p1[i]] + p2[i] + solve((state ^ 1 << (i - 1)), p1[i]));
        }
    }
    return dp[state][last] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        memset(adj, -1, sizeof adj);
        for (int i = 0; i < (1 << 13); i++) {
            for (int j = 0; j < 55; j++) {
                dp[i][j] = (double)(INT_MIN);
            }
        }

        for (int i = 0; i < 55; i++) {
            for (int j = 0; j < 55; j++) {
                adj[i][j] = INT_MAX;
            }
        }
        for (int i = 0, u, v; i < M; i++) {
            double cst;
            cin >> u >> v >> cst;
            adj[u][v] = adj[v][u] = min(adj[u][v], cst);
        }
        cin >> P;
        for (int i = 1; i <= P; i++) {
            cin >> p1[i] >> p2[i];
        }

        for (int i = 0; i <= N; i++) adj[i][i] = 0;
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        double ans = solve((1 << P) - 1, 0);
        cout << "ans " << ans << endl;
        if (ans <= 0.0) {
            cout << "Don’t leave the house\n";
        } else {
            cout << "Daniel can save $" << fixed << setprecision(2) << ans << endl;
        }
    }

    return 0;
}
