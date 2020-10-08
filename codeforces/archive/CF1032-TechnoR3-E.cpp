#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[105];
int ans, ct[105];
bool dp[105][10005][105][2];
int mx;
set<int> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ct[arr[i]]++;
        S.insert(arr[i]);
    }
    for (int i = 101; i >= 1; i--) {
        for (int j = 0; j <= 10000; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int s = 0; s < 2; s++) {
                    if (i == 101) {
                        dp[i][j][k][s] = (j == 0 && k == 0 && s == 0) ? true : false;
                        continue;
                    }
                    dp[i][j][k][s] = dp[i + 1][j][k][s];

                    for (int a = 1; a <= ct[i]; a++) {
                        if (j >= i * a && k >= a) {
                            dp[i][j][k][s] |= dp[i + 1][j - a * i][k - a][s == 0 ? 1 : 0];
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= ct[i]; j++) {
            if (!dp[1][j * i][j][0]) ans = max(ans, (j == ct[i] && S.size() == 2) ? N : j);
        }
    }
    cout << ans << endl;

    return 0;
}
