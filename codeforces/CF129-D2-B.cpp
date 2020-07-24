#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adjList[105];
bool vis[105];
map<int, int> deg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ans = 0;
    while (true) {
        vector<int> v;
        for (auto p : deg) {
            if (p.second == 1) {
                vis[p.first] = true;
                deg[p.first]--;
                v.push_back(p.first);
            }
        }
        if (v.size() == 0) break;
        ans++;
        for (auto x : v) {
            for (auto y : adjList[x]) {
                if (!vis[y]) {
                    deg[y]--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
