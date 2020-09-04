#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, K;
ll h[15], cards[mxN + 5], players[mxN + 5];
ll dp[505][5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0, x; i < K * N; i++) {
        cin >> x;
        cards[x]++;
    }
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        players[x]++;
    }
    for (int i = 1; i <= K; i++) cin >> h[i];
    for (int i = 0; i < 505; i++) {
        for (int j = 0; j < 5005; j++) {
            if (i == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = -1;
            for (int x = 0; x <= min(K, j); x++) {
                if (dp[i - 1][j - x] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + h[x]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 100000; i++) {
        if (players[i] == 0) continue;
        ans += dp[players[i]][cards[i]];
    }
    cout << ans << endl;

    return 0;
}
