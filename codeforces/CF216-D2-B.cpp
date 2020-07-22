#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[105];
int arr[105] = {};
int N, M;
int ans = 0;
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
        if (arr[i] == 0) {
            arr[i] = 1;
            if (adjList[i].size() == 2) {
                int a = adjList[i][0], b = adjList[i][1];
                if (find(adjList[a].begin(), adjList[a].begin(), b) != adjList[a].end()) {
                    arr[a] = 2;
                    arr[b] = -1;
                    ans++;
                } else {
                    arr[a] = 2;
                    arr[b] = 2;
                }
            } else if (adjList[i].size() == 1) {
                arr[adjList[i][0]] = 2;
            }
        } else if (arr[i] != -1) {
            if (adjList[i].size() == 1) {
                arr[adjList[i][0]] = 3 - arr[i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
