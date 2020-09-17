#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 200010
bool debug = true;

int Q, N, arr[MXN];
int dp[MXN][3], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        ans = 0;
        for (int i = 0; i <= N + 5; i++) {
            for (int j = 0; j < 3; j++) dp[i][j] = 0;
        }

        cin >> N;
        for (int i = 1; i <= N; i++) cin >> arr[i];

        sort(arr + 1, arr + N + 1);

        for (int i = 1; i <= N; i++) {
            dp[i][0] = arr[i];
            for (int j = max(1, i - 500); j < i; j++) {
                if (arr[i] % arr[j] != 0) {
                    if (debug) cout << "i j " << i << " " << j << endl;
                    dp[i][1] = max(dp[i][1], arr[i] + dp[j][0]);
                    dp[i][2] = max(dp[i][2], arr[i] + dp[j][1]);
                }
            }
            for (int j = 0; j < 3; j++) ans = max(ans, dp[i][j]);
        }

        cout << ans << "\n";
    }

    return 0;
}
