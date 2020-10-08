#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, Q;
set<int> C;
vector<ii> adjList[105];
vector<int> tempal[105];  //CLEAR
bool vis[105];            //CLEAR

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    for (auto u : tempal[x]) {
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
        C.insert(c);
    }
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int u, v;
        cin >> u >> v;

        int ans = 0;
        for (auto c : C) {
            for (int i = 0; i < 105; i++) vis[i] = false;
            for (int i = 0; i < 105; i++) tempal[i].clear();
            for (int i = 0; i < 105; i++) {
                for (auto p : adjList[i]) {
                    if (p.second == c) {
                        tempal[i].push_back(p.first);
                    }
                }
            }
            dfs(u);
            if (vis[v]) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
