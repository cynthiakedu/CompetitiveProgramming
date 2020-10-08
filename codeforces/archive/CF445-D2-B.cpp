#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
bool vis[55];
ll ct = 0;
vector<int> al[55];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    ct++;
    for (auto y : al[x]) {
        dfs(y);
    }
}

ll p(ll x, ll y) {
    if (y == 0) return 1;
    ll z = p(x, y / 2);
    return z * z * (y % 2 == 1 ? x : 1);
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
    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        ct = 0;
        dfs(i);
        ans *= p(2, ct - 1);
    }

    cout << ans << endl;
    return 0;
}
