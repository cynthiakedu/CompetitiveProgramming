#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

vector<int> adjIn[5005], adjOut[5005], adj[5005];
int N, M, S;
bool vis[5005];

int p[5005], r[5005];

int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
}
void dfs(int u) {
    vis[u] = true;
    for (int v : adjOut[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> S;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adjOut[u].push_back(v);
        adjIn[v].push_back(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(S);

    vector<int> v;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        vector<int> nodes;
        queue<int> q;
        vector<int> dist(N + 15);
        q.push(i);
        // while ()

        if (adjIn[i].size() == 0) ans++;
        v.push_back(i);
    }
    set<int> roots;
    for (int x : v) {
        roots.insert(findSet(x));
    }

    cout << ans << endl;
    return 0;
}
