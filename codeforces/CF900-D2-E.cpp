#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, M;
string s;

int cum[2][2][mxN + 5], cumQ[mxN + 5];
int dp[mxN + 5][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> s >> M;

    for (int i = 1; i <= N; i++) {
        char c = s[i - 1] - 'a';
        if (c != 0 && c != 1) {
            cumQ[i]++;
        } else {
            cum[c][i % 2][i]++;
        }
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                cum[x][y][i] += cum[x][y][i - 1];
            }
        }
        cumQ[i] += cumQ[i - 1];
    }

    for (int i = N; i >= 1; i--) {
        for (int j = 0; j < 2; j++) dp[i][j] = dp[i + 1][j];
        int r = i + M - 1, ct = 0;
        if (r > N) continue;

        ct = cum[0][1 - (i % 2)][r] - cum[0][1 - (i % 2)][i - 1];
        ct += cum[1][i % 2][r] - cum[1][i % 2][i - 1];
        if (ct > 0) continue;

        int ctQ = cumQ[r] - cumQ[i - 1], newNum = 1 + dp[r + 1][0], newMod = ctQ + dp[r + 1][1];
        bool ok2 = (newNum == dp[i][0] && newMod < dp[i][1]);
        if (newNum > dp[i][0] || ok2) {
            dp[i][0] = newNum;
            dp[i][1] = newMod;
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
