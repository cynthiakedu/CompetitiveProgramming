#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 100005
bool debug = false;

ll N, M, MOD, ct[3], arr[505], dp[505][505];

ll solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 && j == 0) return 1;

    ll& ret = dp[i][j];
    ret = ((ll)i * j * solve(i - 1, j)) % MOD;
    if (i > 1) {
        ll temp = ((((ll)i * (i - 1) / 2) % MOD) * solve(i - 2, j + 2)) % MOD;
        ret = (ret + temp) % MOD;
    }
    if (j > 1) {
        ll temp = ((((ll)j * (j - 1) / 2)) % MOD * solve(i, j - 2)) % MOD;
        ret = (ret + temp) % MOD;
    }

    if (debug) cout << "solve " << i << " " << j << " " << ret << endl;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> N >> M >> MOD;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            arr[j] += c - '0';
        }
    }
    for (int i = 1; i <= N; i++) ct[arr[i]]++;
    cout << solve(ct[0], ct[1]) << "\n";
    return 0;
}
