//from tmwilliamlin168

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N, M;
const int mxN = 1e5 + 5;
vector<int> adj[mxN];
ll P[mxN], H[mxN], SP[mxN], A[mxN];
bool ok = true;

void dfs(int x, int p = -1) {
    SP[x] = P[x];
    ll sa = 0;
    for (int y : adj[x]) {
        if (y == p) continue;
        dfs(y, x);
        if (!ok) return;
        SP[x] += SP[y];
        sa += A[y];
    }
    if ((SP[x] & 1) ^ (H[x] & 1) || SP[x] < H[x]) ok = false;
    A[x] = (SP[x] + H[x]) / 2;
    if (A[x] < sa) ok = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < mxN; i++) adj[i].clear();
        ok = true;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) cin >> P[i];
        for (int i = 1; i <= N; i++) cin >> H[i];
        for (int i = 0, u, v; i < N - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}