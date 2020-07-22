#include <bits/stdc++.h>
using namespace std;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;
        vector<int> adjList[105];
        map<int, int> indeg;

        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            adjList[x].push_back(y);
            indeg[y]++;
        }

        queue<int> q;
        vector<int> topSort;
        bool vis[105];

        for (int i = 1; i <= N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topSort.push_back(u);
            for (auto v : adjList[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < topSort.size(); i++) cout << topSort[i] << (i == (topSort.size() - 1) ? "\n" : " ");
    }

    return 0;
}
