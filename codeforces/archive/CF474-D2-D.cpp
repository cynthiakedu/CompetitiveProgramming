#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int T, K;
ll dp[100005], cum[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T >> K;

    dp[0] = 1;
    for (int i = 1; i < 100005; i++) {
        dp[i] = dp[i - 1];
        if (i - K >= 0) {
            dp[i] = (dp[i] + dp[i - K]) % MOD;
        }
    }
    for (int i = 0; i < 100005; i++) {
        cum[i] = dp[i];
        if (i > 0) cum[i] = (cum[i] + cum[i - 1]) % MOD;
    }

    for (int t = 0, a, b; t < T; t++) {
        cin >> a >> b;
        cout << (cum[b] - cum[a - 1] + 2 * MOD) % MOD << endl;
    }

    return 0;
}
