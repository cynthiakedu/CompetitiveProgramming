#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> adjList[100005];
map<int, int> indeg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            adjList[i].push_back(y);
            indeg[y]++;
        }
    }

    queue<int> q;
    vector<int> ord;
    bool vis[100005] = {false};

    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) {
            vis[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ord.push_back(u);
        for (auto v : adjList[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    int ans[100005] = {};
    ans[ord[0]] = 0;
    for (int i = 1; i < ord.size(); i++) {
        ans[ord[i]] = ord[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
