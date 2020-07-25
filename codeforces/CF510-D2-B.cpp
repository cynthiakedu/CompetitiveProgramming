#include <bits/stdc++.h>
using namespace std;
int N, M;
char arr[55][55];
bool vis[55][55];
bool hasCycle = false;
char color;

void dfs(int x, int y, int px = -1, int py = -1) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (arr[x][y] != color) return;
    if (vis[x][y]) {
        hasCycle = true;
        return;
    }
    vis[x][y] = true;
    if (x + 1 != px || y != py) dfs(x + 1, y, x, y);
    if (x - 1 != px || y != py) dfs(x - 1, y, x, y);
    if (x != px || y - 1 != py) dfs(x, y - 1, x, y);
    if (x != px || y + 1 != py) dfs(x, y + 1, x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j]) continue;
            color = arr[i][j];
            dfs(i, j);
            if (hasCycle) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
