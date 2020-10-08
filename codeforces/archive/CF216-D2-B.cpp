#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[105];
int arr[105] = {};
bool vis[105];
int N, M;
int ans = 0;
int rt;
bool hasCycle = false;
int ct = 0, numOdd = 0, mnOddSize = INT_MAX;

void dfs(int x, int p = -1) {
    if (vis[x]) {
        if (x == rt && rt != p) {
            hasCycle = true;
        }
        return;
    }
    vis[x] = true;
    ct++;
    for (auto y : adjList[x]) {
        if (y == p) continue;
        dfs(y, x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        ct = 0;
        rt = i;
        hasCycle = false;
        dfs(i);
        if (hasCycle && ct % 2 == 1) {
            ans++;
        } else if (ct % 2 == 1) {
            numOdd++;
        }
    }

    cout << ans + (numOdd % 2 == 1 ? 1 : 0) << endl;

    return 0;
}
