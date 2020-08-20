#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> adj[5005];
int ans[5005];
int mx, mn;

int dfs(int u, int p = -1) {
    int ret = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        ret = max(ret, 1 + dfs(v, u));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        mx = INT_MIN;
        mn = INT_MAX;
        for (int i = 0; i < 5005; i++) adj[i].clear();
        for (int i = 1, x; i <= N; i++) {
            cin >> x;
            for (int j = 1, y; j <= x; j++) {
                cin >> y;
                adj[i].push_back(y);
            }
        }
        for (int i = 1; i <= N; i++) {
            int x = dfs(i);
            ans[i] = x;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        vector<int> v1, v2;
        for (int i = 1; i <= N; i++) {
            if (ans[i] == mn) {
                v1.push_back(i);
            }
            if (ans[i] == mx) {
                v2.push_back(i);
            }
        }
        cout << "Best Roots  : ";
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << (i == v1.size() - 1 ? "\n" : " ");
        }
        cout << "Worst Roots : ";
        for (int i = 0; i < v2.size(); i++) {
            cout << v2[i] << (i == v2.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
