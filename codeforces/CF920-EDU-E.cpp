#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, M, ans, ans2;
set<int> adj[mxN + 5], S;
vector<int> v;

void dfs(int u) {
    ans2++;
    S.erase(u);

    if (!S.size()) return;
    int x = *S.begin();

    while (true) {
        if (!adj[u].count(x)) dfs(x);
        set<int>::iterator it = S.upper_bound(x);
        if (it == S.end()) break;
        x = *it;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= N; i++) S.insert(i);

    while (S.size()) {
        ans++;
        ans2 = 0;
        int u = *S.begin();
        dfs(u);
        v.push_back(ans2);
    }
    cout << ans << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");

    return 0;
}
