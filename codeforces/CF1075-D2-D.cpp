#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1000;
int T, N, k1, k2;
vector<int> adj[mxN + 5];
int me[mxN + 5], li[mxN + 5];
int a, b, c, d;
bool vis[mxN + 5];

void dfs(int u, int p = -1) {
    if (me[u] == 1) {
        if (c == -1) {
            c = u;
        }
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(me, 0, sizeof me);
        memset(li, 0, sizeof li);
        memset(vis, false, sizeof vis);
        for (int i = 0; i < mxN + 5; i++) adj[i].clear();
        c = -1;

        cin >> N;
        for (int i = 0, u, v; i < N - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cin >> k1;
        for (int i = 0, x; i < k1; i++) {
            cin >> x;
            me[x] = 1;
        }
        cin >> k2;
        for (int i = 0, x; i < k2; i++) {
            cin >> x;
            li[x] = 1;
            a = x;
        }

        cout << "B " << a << endl;
        cin >> b;
        dfs(b);
        cout << "A " << c << endl;
        cin >> d;
        if (li[d] == 1) {
            cout << "C " << c << endl;
        } else {
            cout << "C -1" << endl;
        }
    }

    return 0;
}
