#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, M, adj[35][35];
int adj2[35][35];
int t = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> M) {
        cout << "matrix for city " << t << endl;
        t++;
        if (M == 0) continue;

        memset(adj, 0, sizeof adj);
        memset(adj2, 0, sizeof adj2);

        N = 0;
        for (int i = 0, x, y; i < M; i++) {
            cin >> x >> y;
            adj[x][y]++;
            adj2[x][y]++;
            N = max({N, x, y});
        }

        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    adj[i][j] += adj[i][k] * adj[k][j];
                }
            }
        }
        for (int i = 0; i <= N; i++) {
            if (adj[i][i] > 0) {
                // cout << "cycle " << i << endl;
                adj2[i][i] = 2;
            }
        }

        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    if (adj[i][j] > 0) {
                        if (adj[i][k] && adj[k][j]) {
                            if (adj2[i][k] == 2 || adj2[k][j] == 2) {
                                adj2[i][j] = 2;
                            }
                        }

                        adj2[i][j] = max({adj2[i][j], adj2[i][i], adj2[j][j]});
                    }
                }
            }
        }

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (adj2[i][j] == 2) {
                    cout << -1;
                } else {
                    cout << adj[i][j];
                }
                cout << (j == N ? "\n" : " ");
            }
        }
    }

    return 0;
}

// 9
// 0 1 0 2 0 3
// 0 4 1 4 2 1
// 2 0
// 3 0
// 3 1

// 6
// 0 1
// 0 2
// 1 2
// 2 3
// 3 2
// 3 4