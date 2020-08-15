#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int D, N, K;
ll dp[(1 << 13)][150];

ll solve(int x, int k) {
    if (x == 0)
        return k == 0 ? 1 : 0;
    if (dp[x][k] != -1) {
        return dp[x][k];
    }

    int ct = 0, ct1 = 0;
    for (int i = 0; i < 12; i++) {
        if (x & (1 << i)) ct++;
    }
    dp[x][k] = 0;
    for (int i = 11; i >= 0; i--) {
        if (x & (1 << i)) {
            int amt = ct1;

            if (amt <= k) {
                dp[x][k] += solve((x ^ (1 << i)), k - amt);
            }
            ct1++;
        }
    }
    return dp[x][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> D;
    memset(dp, -1, sizeof dp);
    for (int d = 0; d < D; d++) {
        cin >> N >> K;
        int x = (1 << (N)) - 1;
        cout << solve(x, K) << endl;
    }

    return 0;
}
