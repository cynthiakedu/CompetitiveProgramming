#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll arr[200005];
vector<int> adj[200005];
ll mx[200005], s[200005];
ll ans = LLONG_MIN;

void dfs(int u, int p = -1) {
    s[u] = arr[u];
    vector<ll> mxVals;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        s[u] += s[v];
        mxVals.push_back(mx[v]);
    }

    sort(mxVals.begin(), mxVals.end());
    mx[u] = s[u];
    if (mxVals.size()) mx[u] = max(mx[u], mxVals[mxVals.size() - 1]);

    if (mxVals.size() >= 2) {
        ans = max(ans, mxVals[mxVals.size() - 1] + mxVals[mxVals.size() - 2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 200005; i++) mx[i] = LLONG_MIN;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if (ans == LLONG_MIN) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
