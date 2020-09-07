#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int e[mxN + 5], o[mxN + 5], evenCt[mxN + 5], oddCt[mxN + 5];
ll s = 0;

void dfs(int u, int p = -1) {
    evenCt[u] = 1;
    vector<int> ve, vo;
    ll sub = 0;
    for (int v : adj[u]) {
        dfs(v, u);
        evenCt[u] += oddCt[v];
        oddCt[u] += evenCt[v];
        ve.push_back(e[v]);
        vo.push_back(o[v]);
        e[u] += o[v];
        o[u] += oddCt[v] + e[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
