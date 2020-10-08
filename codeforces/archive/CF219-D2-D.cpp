#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N;

vector<ii> adj[mxN + 5];
int ans1[mxN + 5];
vector<int> v;

int dfs(int u, int c = 0, int p = -1) {
    ans1[u] = c;
    int ret = 0;
    for (auto v : adj[u]) {
        int v1 = v.first, v2 = v.second;
        if (v1 == p) continue;
        int x = dfs(v1, c + (v2 == 1 ? 1 : -1), u);
        ret += (v2 == 0 ? 1 : 0);
        ret += x;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 0});
    }
    int mn = INT_MAX;
    int ans3 = dfs(1);
    for (int i = 1; i <= N; i++) mn = min(mn, ans1[i] + ans3);
    for (int i = 1; i <= N; i++) {
        if (ans1[i] + ans3 == mn) {
            v.push_back(i);
        }
    }
    cout << mn << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");

    return 0;
}
