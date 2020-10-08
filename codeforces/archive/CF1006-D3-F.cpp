#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll N, M, K, arr[25][25], ans = 0;
vector<ll> dp[2][25][25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][1][1].push_back(arr[1][1]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; i + j - 1 <= (N + M) / 2 && j <= M; j++) {
            if (i > 1)
                for (ll x : dp[0][i - 1][j]) dp[0][i][j].push_back(x ^ arr[i][j]);
            if (j > 1)
                for (ll x : dp[0][i][j - 1]) dp[0][i][j].push_back(x ^ arr[i][j]);
        }
    }

    dp[1][N][M].push_back(K ^ arr[N][M]);
    for (int i = N; i >= 1; i--) {
        for (int j = M; j >= (N + M) / 2 + 1 - i && j >= 1; j--) {
            if (i < N)
                for (ll x : dp[1][i + 1][j]) dp[1][i][j].push_back(x ^ arr[i][j]);
            if (j < M)
                for (ll x : dp[1][i][j + 1]) dp[1][i][j].push_back(x ^ arr[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        int j = (M + N) / 2 + 1 - i;
        if (j < 1 || j > M) continue;
        map<ll, ll> m;
        for (ll x : dp[0][i][j]) m[x ^ arr[i][j]]++;
        for (ll x : dp[1][i][j]) ans += m[x];
    }

    cout << ans << endl;

    return 0;
}
