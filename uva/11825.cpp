#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int t = 0;
vector<int> adj[20];
bool vis[20];
int ct = 0;
int ans = 0;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    ct++;
    for (auto v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        ans = 0;
        memset(vis, false, sizeof vis);
        for (int i = 0; i < 20; i++) adj[i].clear();
        t++;
        cout << "Case " << t << ": ";
        for (int i = 0; i < N; i++) {
            int a, x;
            cin >> a;
            for (int j = 0; j < a; j++) {
                cin >> x;
                adj[i].push_back(x);
            }
        }
        for (int i = 0; i < N; i++) {
            ct = 0;
            if (vis[i]) continue;
            dfs(i);
            ans = max(ans, ct);
        }
        cout << ans << endl;
    }

    return 0;
}
