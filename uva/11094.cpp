#include <bits/stdc++.h>
using namespace std;
int M, N, x, y;
char arr[30][30];
bool vis[30][30];
int ct = 0;
char c;

void dfs(int x, int y) {
    if (x < 0 || x >= M) return;
    if (vis[x][y]) return;
    if (arr[x][y] != c) return;
    vis[x][y] = true;
    ct++;
    dfs(x, (y + 1) % N);
    dfs(x, (y - 1 + N) % N);
    dfs(x - 1, y);
    dfs(x + 1, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> M) && (cin >> N)) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        cin >> x >> y;
        c = arr[x][y];
        dfs(x, y);
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!vis[i][j] && arr[i][j] == c) {
                    ct = 0;
                    dfs(i, j);
                    ans = max(ans, ct);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}