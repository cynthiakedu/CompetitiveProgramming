#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int dp[mxN + 5][2];
vector<int> adj[mxN + 5];
int N, root;

int dfs(int u, int t, int p = -1) {  // t = 1 /0 is this node before/after its parent
    if (dp[u][t] != -1) return dp[u][t];
    int total = 0, a = 0, c = 0;
    for (int v : adj[u]) {
        if (p == v) continue;
        int m = dfs(v, 1, u);
        int n = dfs(v, 0, u);
        total++;
        if (m && n)
            c++;
        else if (m)
            a++;
    }
    if (t == 0) {
        if (a % 2 == total % 2 || c > 0)
            dp[u][t] = true;
        else
            dp[u][t] = false;
    } else {
        if (a % 2 != total % 2 || c > 0)
            dp[u][t] = true;
        else
            dp[u][t] = false;
    }
    return dp[u][t];
}

void dfs2(int u, int t, int p = -1) {
    int total = 0;
    vector<int> c, a, b;
    for (int v : adj[u]) {
        if (p == v) continue;
        int m = dfs(v, 1, u);
        int n = dfs(v, 0, u);
        total++;
        if (m && n)
            c.push_back(v);
        else if (m)
            a.push_back(v);
        else
            b.push_back(v);
    }
    if (t == 0) {
        if (a.size() % 2 != total % 2) {
            int x = c.back();
            c.pop_back();
            a.push_back(x);
        }
    } else {
        if (a.size() % 2 == total % 2) {
            int x = c.back();
            c.pop_back();
            a.push_back(x);
        }
    }
    for (int v : a) dfs2(v, 1, u);
    cout << u << endl;
    for (int v : b) dfs2(v, 0, u);
    for (int v : c) dfs2(v, 0, u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> N;
    for (int i = 1, p; i <= N; i++) {
        cin >> p;
        if (p != 0) {
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    bool ok = dfs(1, 0);
    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    dfs2(1, 0);

    return 0;
}
