#include <bits/stdc++.h>
using namespace std;
int T, N;
char arr[105][105];
vector<int> d = {-1, 0, 1};

void dfs(int x, int y) {
    if (x < 0 || x >= N) return;
    if (y < 0 || y >= N) return;
    if (arr[x][y] == '.') return;
    arr[x][y] = '.';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << (-3) / 2 << endl;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 'x') {
                    ans++, dfs(i, j);
                }
            }
        }
        cout << "Case " << t + 1 << ": " << ans << endl;
    }

    return 0;
}