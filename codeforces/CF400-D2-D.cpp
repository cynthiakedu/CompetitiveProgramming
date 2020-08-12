#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K;
vector<int> adj[100005];
int C[505], cumC[505];
ll arr[505][505];
int ct = 0;
bool vis[100005];
int root[100005];

void dfs(int x, int r, int p = -1) {
    if (vis[x]) return;
    vis[x] = true;
    root[x] = r;
    ct++;
    for (auto y : adj[x]) {
        dfs(y, r, x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(arr, -1, sizeof arr);

    cin >> N >> M >> K;
    for (int i = 1; i <= K; i++) {
        cin >> C[i];
        cumC[i] = C[i] + cumC[i - 1];
    }

    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        ll x;
        cin >> x;
        int tu = (int)(lower_bound(cumC + 1, cumC + K + 1, u) - cumC);
        int tv = (int)(lower_bound(cumC + 1, cumC + K + 1, v) - cumC);
        if (x == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (tu != tv) {
            if (arr[tu][tv] != -1) {
                arr[tu][tv] = min(arr[tu][tv], x);
                arr[tv][tu] = min(arr[tv][tu], x);
            } else {
                arr[tu][tv] = x;
                arr[tv][tu] = x;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        dfs(i, i);
    }
    for (int i = 1; i <= K; i++) {
        int x = cumC[i - 1] + 1, amt = C[i];
        for (int j = x; j <= cumC[i]; j++) {
            if (!(root[j] == root[x])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= K; i++) arr[i][i] = 0;

    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K; j++) {
                if (arr[i][k] == -1 || arr[k][j] == -1) continue;
                if (arr[i][j] == -1) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                } else {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            cout << arr[i][j] << (j == K ? "\n" : " ");
        }
    }

    return 0;
}
