#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<int> v;
vector<int> adj[2005];
int N;
int mx = 0;

void dfs(int u, int d = 0) {
    mx = max(mx, d);
    for (auto v1 : adj[u]) {
        dfs(v1, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        if (x == -1) {
            v.push_back(i);
        } else {
            adj[x].push_back(i);
        }
    }
    for (auto x : v) {
        dfs(x);
    }
    cout << mx + 1 << endl;

    return 0;
}
