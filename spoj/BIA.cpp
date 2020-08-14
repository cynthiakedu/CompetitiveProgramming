#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<int> adj[5005];
set<int> ans;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int t = 0; t < 10; t++) {
        for (int i = 0; i < 5005; i++) adj[i].clear();
        ans.clear();
        cin >> N >> M;
        for (int i = 0, u, v; i < M; i++) {
            cin >> u >> v;
            adj[v].push_back(u);
        }
        for (int i = 1; i <= N; i++) {
            if (adj[i].size() == 1) {
                ans.insert(adj[i][0]);
            }
        }
        ans.insert(1);
        vector<int> v(ans.begin(), ans.end());
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }

    return 0;
}
