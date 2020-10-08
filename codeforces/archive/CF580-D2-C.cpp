#include <bits/stdc++.h>
using namespace std;
int N, M, arr[100005];
vector<int> al[100005];
bool vis[100005];
int ans = 0;

void dfs(int u, int c = 0) {
    int numVis = 0;
    int newCt = arr[u] ? c + 1 : 0;
    if (newCt > M) return;
    for (auto v : al[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        numVis++;
        dfs(v, newCt);
    }
    if (numVis == 0) ans++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    vis[1] = true;
    dfs(1);
    cout << ans << endl;

    return 0;
}
