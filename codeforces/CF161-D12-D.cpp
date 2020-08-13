#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll m[50005][505];
int N, K;
vector<int> adj[50005];
ll ct = 0;

void dfs(int u, int p = -1) {
    ll s = 0;
    ll sub = 0;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = K; i >= 1; i--) {
            m[v][i] = m[v][i - 1];
            m[u][i] += m[v][i - 1];
        }
        m[v][0] = 0;
        for (int i = 0; i <= K; i++) {
            sub += m[v][i] * m[v][K - i];
        }
    }
    m[u][0] = 1;
    for (int i = 0; i <= K; i++) {
        s += m[u][i] * m[u][K - i];
    }
    ct += (s - sub) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0, x, y; i < N - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout << ct << endl;

    return 0;
}
