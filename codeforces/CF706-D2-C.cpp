#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N;
bool can[100005][2][2];
string arr[100005];
ll C[100005];
ll dp[100005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string a = "abe", d = "abcd";
    // cout << (a < d ? "yes" : "no") << endl;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N - 1; i++) {
        string a = arr[i], b = arr[i];
        string c = arr[i + 1], d = arr[i + 1];
        reverse(b.begin(), b.end());
        reverse(d.begin(), d.end());
        if (a <= c) can[i][0][0] = true;
        if (a <= d) can[i][0][1] = true;
        if (b <= c) can[i][1][0] = true;
        if (b <= d) can[i][1][1] = true;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            if (i == N - 1) {
                dp[i][j] = j == 1 ? C[i] : 0;
                continue;
            }
            ll& d = dp[i][j];
            d = LLONG_MAX;
            for (int k = 0; k < 2; k++) {
                if (can[i][j][k] && dp[i + 1][k] != LLONG_MAX) {
                    d = min(d, (j == 1 ? C[i] : 0) + dp[i + 1][k]);
                }
            }
        }
    }
    ll ans = min(dp[0][0], dp[0][1]);
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
