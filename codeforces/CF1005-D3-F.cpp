#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K;
vector<ii> adj[200005];
vector<int> ans1[200005];
int temp[200005];
vector<string> ans2;
int ct = 0;

void solve(int idx) {
    if (idx == N + 1) {
        ct++;
        string s = "";
        for (int i = 1; i <= M; i++) s += (char)(temp[i] + '0');
        ans2.push_back(s);
        return;
    }
    for (auto x : ans1[idx]) {
        if (ct >= K) return;
        temp[x] = 1;
        solve(idx + 1);
        temp[x] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    queue<int> q;
    vector<int> dist(200005, -1);
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v.first] == -1) {
                dist[v.first] = dist[u] + 1;
                q.push(v.first);
            }
            if (dist[v.first] == dist[u] + 1) {
                ans1[v.first].push_back(v.second);
            }
        }
    }
    solve(2);
    cout << ans2.size() << endl;
    for (auto s : ans2) cout << s << endl;

    return 0;
}
