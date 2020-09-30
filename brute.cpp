#include <bits/stdc++.h>
using namespace std;

int R, C, N, K;
vector<int> blocks[3005];
map<int, int> m[3005];
long long ans1[3005], ans2;
int board[3005][3005], bruteAns, dp[3005][3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> N >> K;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        blocks[x].push_back(y);
        board[x][y] = 1;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            dp[i][j] = board[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    for (int a = 1; a <= R; a++) {
        for (int b = a; b <= R; b++) {
            for (int c = 1; c <= C; c++) {
                for (int d = c; d <= C; d++) {
                    int num = dp[b][d] - dp[a - 1][d] - dp[b][c - 1] + dp[a - 1][c - 1];
                    if (num >= K) bruteAns++;
                }
            }
        }
    }
    cout << "Brute force answer = " << bruteAns << endl;

    return 0;
}
