#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
vector<int> al[150005];
bool vis[150005];
ll ct = 0, e = 0;

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    ct += 1;
    e += al[x].size();
    for (auto y : al[x]) {
        dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        ct = 0;
        e = 0;
        dfs(i);
        if ((ct * (ct - 1)) / 2 != e / 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
