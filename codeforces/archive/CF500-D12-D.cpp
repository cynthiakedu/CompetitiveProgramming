#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, Q;
ll w[100005];
ll ct[100005];
vector<ii> adj[100005];  //neighbor, edge id

ll dfs(int u, int p = -1) {
    ll ret = 1;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        ll x = dfs(v.first, u);
        ret += x;
        ct[v.second] = x;
    }
    // cout << "vis " << u << " " << ret << endl;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        ll l;
        cin >> a >> b >> l;
        w[i] = l;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    dfs(1);
    ll s = 0;
    for (int i = 1; i <= N - 1; i++) {
        s += ct[i] * (N - ct[i]) * w[i];
    }

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int a;
        ll l;
        cin >> a >> l;
        ll diff = l - w[a];
        w[a] = l;
        s += ct[a] * (N - ct[a]) * diff;
        cout << setprecision(16) << 1.0 * s * 3 / ((ll)N * (N - 1) / 2) << endl;
    }

    return 0;
}
