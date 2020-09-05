#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K;
bool dp[1005][1005][2];
int ans[1005][1005][2];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cin >> s;

    for (int i = N + 1; i >= 1; i--) {
        for (int j = 0; j <= K; j++) {
            for (int x = 0; x < 2; x++) {  // 1 is more win, 0 is more lost
                bool& ret = dp[i][j][x];
                int& tmp = ans[i][j][x];
                if (i == N + 1) {
                    ret = (j == K ? true : false);
                    continue;
                }
                if (j == K) {
                    ret = false;
                    continue;
                }
                if (s[i - 1] == 'D' || (dp[i + 1][j][x] && s[i - 1] == '?')) {
                    ret = dp[i + 1][j][x];
                    tmp = 0;
                    continue;
                }
                if (s[i - 1] != 'L') {
                    if (x == 1) {
                        ret = dp[i + 1][j + 1][1];
                    } else if (j == 1) {
                        ret = dp[i + 1][0][1];
                    } else {
                        ret = dp[i + 1][j - 1][0];
                    }
                    tmp = 1;
                    if (ret) {
                        continue;
                    }
                }
                if (s[i - 1] != 'W') {
                    if (x == 0) {
                        ret = dp[i + 1][j + 1][0];
                    } else if (j == 0) {
                        ret = dp[i + 1][1][0];
                    } else {
                        ret = dp[i + 1][j - 1][1];
                    }

                    tmp = -1;
                }
            }
        }
    }
    bool ok = dp[1][0][1];
    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }
    int j = 0, k = 1;
    string ans2 = "";
    for (int i = 1; i <= N; i++) {
        if (ans[i][j][k] == 0) {
            ans2 += "D";
            continue;
        }
        int x = ans[i][j][k];
        ans2 += (x == 1 ? "W" : "L");
        if (x == -1) x++;
        if (k == x) {
            j++;
        } else if (k == 0 && j == 1) {
            j = 0;
            k = 1;
        } else if (k == 1 && j == 0) {
            j = 1;
            k = 0;
        } else {
            j--;
        }
    }
    cout << ans2 << endl;
    return 0;
}
