#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, E, S, T;
double adj[105][105];
double adj2[105][105];
double p[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    // freopen("./output.txt", "w", stdout);
    while ((cin >> N) && (cin >> E)) {
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                adj[i][j] = -1.0;
                adj2[i][j] = -1.0;
            }
        }
        cin >> S >> T;
        for (int i = 0; i < E; i++) {
            int u, v;
            double a, b;
            cin >> u >> v;
            cin >> a >> b;
            if (adj[u][v] == -1.0 || a < adj[u][v]) {
                adj[u][v] = a;
                adj[v][u] = a;
                adj2[u][v] = b;
                adj2[v][u] = b;
            } else if (a == adj[u][v]) {
                if (b < adj2[u][v]) {
                    adj2[u][v] = b;
                    adj2[v][u] = b;
                }
            }
            p[u][v] = u;
            p[v][u] = v;
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (adj[i][k] != -1.0 && adj[k][j] != -1.0) {
                        double a = max(adj[i][k], adj[k][j]);
                        double b = adj2[i][k] + adj2[k][j];
                        if (adj[i][j] == -1 || a < adj[i][j]) {
                            adj[i][j] = a;
                            adj2[i][j] = b;
                            p[i][j] = p[k][j];
                        } else if (a == adj[i][j]) {
                            if (b < adj2[i][j]) {
                                adj2[i][j] = b;
                                p[i][j] = p[k][j];
                            }
                        }
                    }
                }
            }
        }
        int T1 = T;
        vector<int> v = {T};
        while (T != S) {
            T = p[S][T];
            v.push_back(T);
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
        cout << adj2[S][T1] << " " << adj[S][T1] << endl;
    }
    return 0;
}

// 6 9
// 1 6
// 1 2 37.1 10.2
// 2 3 40.5 20.7
// 3 4 42.8 19.0
// 3 1 38.3 15.8
// 4 5 39.7 11.1
// 6 3 36.0 22.5
// 5 6 43.9 10.2
// 2 6 44.2 15.2
// 4 6 34.2 17.4
// 6 9
// 2 3
// 1 2 37.1 10.2
// 2 3 40.5 20.7
// 3 4 42.8 19.0
// 3 1 38.3 15.8
// 4 5 39.7 11.1
// 6 3 36.0 22.5
// 5 6 43.9 10.2
// 2 6 44.2 15.2
// 4 6 34.2 17.4