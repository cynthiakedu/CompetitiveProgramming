#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, M;
vector<int> adj[mxN + 5];

ll ct[2];
ll ans2 = 0;
bool ok = true;
int colors[mxN + 5];

void dfs(int u, int c) {
    colors[u] = c;
    ct[c]++;
    for (int v : adj[u]) {
        if (colors[v] != -1) {
            if (colors[v] != 1 - c) ok = false;
            continue;
        }
        dfs(v, 1 - c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(colors, -1, sizeof colors);

    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (colors[i] != -1) continue;
        ct[0] = ct[1] = 0;
        dfs(i, 0);
        if (!ok) {
            cout << 0 << " " << 1 << endl;
            return 0;
        }
        ans2 += (ct[0] * (ct[0] - 1) / 2) + (ct[1] * (ct[1] - 1) / 2);
    }
    if (ans2 > 0) {
        cout << 1 << " " << ans2 << endl;
        return 0;
    }
    if (M >= 1) {
        cout << 2 << " " << (ll)M * (N - 2) << endl;
        return 0;
    }
    cout << 3 << " " << (ll)N * (N - 1) * (N - 2) / 6 << endl;

    return 0;
}
