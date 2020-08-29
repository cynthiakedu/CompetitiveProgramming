#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, K;
vector<int> adj[mxN + 5];
int ans[mxN + 5];

void dfs(int u, int p = -1) {
    vector<int> ret;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        ret.push_back(ans[v]);
    }
    sort(ret.begin(), ret.end());
    int t = 0;
    for (auto x : ret) {
        int mn = min(t, x);
        t += (x - mn) + 1;
    }
    ans[u] = t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        while (true) {
            cin >> x;
            if (x == 0) break;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    cin >> K;
    dfs(K);
    cout << ans[K] << endl;

    return 0;
}
