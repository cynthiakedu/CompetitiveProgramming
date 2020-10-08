#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
const int mxN = 3e5;
int N, M, U;
vector<ii> adj[mxN + 5];

ll dist[mxN + 5], saved[mxN + 5][2], edgeWeights[mxN + 5];
bool vis[mxN + 5];

vector<ll> ans;
ll ans2 = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < mxN + 5; i++) {
        saved[i][0] = LLONG_MAX;
        dist[i] = -1;  //FORGOT
    }

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edgeWeights[i] = w;
    }
    cin >> U;

    priority_queue<pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> pq;
    pq.push({0LL, {U, 0}});
    dist[U] = 0;
    saved[U][0] = 0;

    while (!pq.empty()) {
        pair<ll, ii> p = pq.top();
        pq.pop();
        ll u = p.second.first, d = p.first;
        ll wid = p.second.second;
        if (d > dist[u]) continue;
        if (d == dist[u]) {
            if (edgeWeights[wid] < saved[u][0]) {
                saved[u][0] = edgeWeights[wid];
                saved[u][1] = wid;
            }
        }
        if (vis[u]) continue;
        vis[u] = true;

        for (auto v : adj[u]) {
            ll d2 = dist[u] + edgeWeights[v.second];
            if (dist[v.first] == -1 || dist[v.first] >= d2) {
                dist[v.first] = d2;
                pq.push({dist[v.first], {v.first, v.second}});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i == U) continue;
        ans2 += saved[i][0];
        ans.push_back(saved[i][1]);
    }
    cout << ans2 << endl;
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << (i == (int)ans.size() - 1 ? "\n" : " ");

    return 0;
}
