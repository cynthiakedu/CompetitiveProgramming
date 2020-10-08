#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 2e5;
ll N, M, K, arr[mxN + 5], cum[mxN + 5], best[2005];
ll dp[2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        cum[i] = cum[i - 1] + arr[i];
    }

    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > K) continue;
        best[a] = max(best[a], b);
    }

    for (int i = 1; i <= K; i++) {
        dp[i] = dp[i - 1] + arr[i];
        for (int s = 1; s <= i; s++) {
            if (best[s] == 0) continue;
            ll b = best[s];
            if (debug) cout << "try " << s << " " << dp[i - s] + (cum[i] - cum[i - (s - b)]) << endl;
            dp[i] = min(dp[i], dp[i - s] + (cum[i] - cum[i - (s - b)]));
        }
        if (debug) cout << "dp " << i << " " << dp[i] << endl;
    }
    cout << dp[K] << endl;
    return 0;
}
