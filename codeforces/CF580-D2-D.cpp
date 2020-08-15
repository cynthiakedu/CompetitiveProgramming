#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll dp[20][(1 << 19)];
int N, M, K;
ll arr[20];
map<ii, ll> m;
ll ans = 0;

ll solve(ll b, ll j) {
    if (dp[b][j] != -1) {
        return dp[b][j];
    }
    if (j == 0) return 0;

    for (int k = 0; k < N; k++) {
        if (j & (1 << k)) {
            ll score = arr[k] + m[{b, k}];
            score += solve(k, j ^ (1 << k));
            dp[b][j] = max(dp[b][j], score);
        }
    }
    return dp[b][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0, x, y; i < K; i++) {
        ll c;
        cin >> x >> y >> c;
        m[{x - 1, y - 1}] = c;
    }
    memset(dp, -1, sizeof dp);

    for (int j = 0; j < (1 << N); j++) {
        int ct = 0;
        for (int k = 0; k < N; k++) {
            if (j & (1 << k)) {
                ct++;
            }
        }
        if (ct == M) {
            ans = max(ans, solve(N, j));
        }
    }
    cout << ans << endl;

    return 0;
}
