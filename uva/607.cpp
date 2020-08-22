#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll dp[1005][2];
ll arr[1005];
int N, L, C;

ll getCost(ll t) {
    if (t == 0) return 0;
    if (t <= 10) return -C;
    return (t - 10) * (t - 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (true) {
        ct++;
        memset(dp, 0, sizeof dp);
        cin >> N;
        if (N == 0) return 0;
        if (ct != 1) cout << endl;
        cin >> L >> C;
        for (int i = 1; i <= N; i++) cin >> arr[i];

        for (int i = N; i >= 1; i--) {
            dp[i][0] = dp[i][1] = LLONG_MAX;
            ll cum = 0;
            for (int j = i; j <= N; j++) {
                cum += arr[j];
                if (cum > L) break;
                ll temp1 = 1 + dp[j + 1][0];
                ll temp2 = getCost(L - cum) + dp[j + 1][1];
                if (temp1 < dp[i][0]) {
                    dp[i][0] = temp1;
                    dp[i][1] = temp2;
                } else if (temp1 == dp[i][0]) {
                    if (temp2 < dp[i][1]) {
                        dp[i][1] = temp2;
                    }
                }
            }
        }
        cout << "Case " << ct << ":" << endl;
        cout << "Minimum number of lectures: " << dp[1][0] << endl;
        cout << "Total dissatisfaction index: " << dp[1][1] << endl;
    }

    return 0;
}
