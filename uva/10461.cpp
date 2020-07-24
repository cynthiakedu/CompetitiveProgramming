#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int V, E, Q, arr[505];
vector<int> al1[505], al2[505];
bool vis[505];
ll ct = 0;

void dfs(int x, vector<int> al[505]) {
    if (vis[x]) return;
    ct += arr[x];
    vis[x] = true;

    for (auto v : al[x]) {
        dfs(v, al);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    while (true) {
        t++;
        cin >> V >> E;
        if (V == 0 && E == 0) return 0;
        cout << "Case #" << t << ":" << endl;

        ll s = 0;
        for (int i = 1; i <= V; i++) {
            cin >> arr[i];
            s += arr[i];
        }
        for (int i = 0; i < 505; i++) {
            al1[i].clear(), al2[i].clear();
        }
        for (int i = 0, u, v; i < E; i++) {
            cin >> u >> v;
            al1[v].push_back(u);
            al2[u].push_back(v);
        }

        cin >> Q;
        for (int i = 0, x; i < Q; i++) {
            cin >> x;
            ll a, b;
            for (int j = 0; j < 505; j++) {
                vis[j] = false;
            }
            ct = 0;
            dfs(x, al1);
            a = ct;
            for (int j = 0; j < 505; j++) {
                vis[j] = false;
            }
            ct = 0;
            dfs(x, al2);
            b = s - (ct - arr[x]);
            cout << b - a << endl;
        }
        cout << endl;
    }

    return 0;
}
