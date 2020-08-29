#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, M, arr[mxN + 5], arr2[mxN + 5];
int dist[mxN + 5];
vector<int> adj[mxN + 5];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof dist);

    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            dist[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (arr2[u] == arr[u]) {
            ans.push_back(u);
            arr2[u]++;
            for (int v : adj[u]) {
                arr2[v]++;
                if (arr2[v] == arr[v]) {
                    q.push(v);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");

    return 0;
}
