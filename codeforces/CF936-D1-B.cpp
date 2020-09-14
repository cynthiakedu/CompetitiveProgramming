#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 5e5;

int N, M, src, p[mxN + 5], dest = -1;
vector<int> adj[mxN + 5];
bool vis[mxN + 5], hasCycle;
set<int> S;

void dfs(int u) {
    vis[u] = true;
    S.insert(u);
    if (debug) cout << "dfs " << u << endl;
    int ct = 0;
    for (int v : adj[u]) {
        ct++;
        if (vis[v]) {
            if (S.count(v)) hasCycle = true;
            continue;
        }
        if (debug) cout << "p " << u << " -> " << v << endl;
        p[v] = u;
        dfs(v);
    }
    S.erase(u);
    if (!ct && u > N) dest = u;  //Set u <= N at first!
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        for (int j = 0, y; j < x; j++) {
            cin >> y;
            adj[i].push_back(y + N);
            adj[i + N].push_back(y);
        }
    }
    cin >> src;

    dfs(src);

    if (dest != -1) {
        cout << "Win" << endl;
        vector<int> ans = {};
        p[src] = -1;
        for (; dest != -1; dest = p[dest]) {
            ans.push_back(dest > N ? dest - N : dest);
        }
        reverse(ans.begin(), ans.end());  //Forgot!
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    } else if (hasCycle) {
        cout << "Draw" << endl;
    } else {
        cout << "Lose" << endl;
    }

    return 0;
}
