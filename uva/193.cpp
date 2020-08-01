#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int M, N, K;
int colors[105];
vector<int> ans;
vector<int> adj[105];

void solve(int idx) {
    if (idx == N + 1) {
        vector<int> v;
        for (int i = 1; i <= N; i++) {
            if (colors[i] == 1) {
                v.push_back(i);
            }
        }
        if (v.size() > ans.size()) ans = v;
        return;
    }
    colors[idx] = 0;
    solve(idx + 1);

    bool ok = true;
    for (auto x : adj[idx]) {
        if (colors[x] == 1) {
            ok = false;
        }
    }
    if (ok) {
        colors[idx] = 1;
        solve(idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M;
    for (int t = 0; t < M; t++) {
        ans.clear();
        for (int i = 0; i < 105; i++) adj[i].clear();
        cin >> N >> K;
        for (int i = 0, u, v; i < K; i++) {
            cin >> u >> v;
            adj[max(u, v)].push_back(min(u, v));
        }
        solve(1);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        cout << endl;
    }

    return 0;
}

// 2
// 6 8
// 1 2
// 1 3
// 2 4
// 2 5
// 3 4
// 3 6
// 4 6
// 5 6
// 6 8
// 1 2
// 1 3
// 2 4
// 2 5
// 3 4
// 3 6
// 4 6
// 5 6