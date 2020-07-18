#include <bits/stdc++.h>
using namespace std;
int N;
string a, b;
int dp[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    N = a.size();

    for (int i = N - 2; i >= 0; i--) {
        dp[i] = dp[i + 1];
        if (a[i] == '0' && b[i] == '0') {
            if (a[i + 1] == '0' || b[i + 1] == '0') {
                dp[i] = max(dp[i], 1 + dp[i + 2]);
            }
            if (i <= N - 3) {
                if (a[i + 1] == '0' && b[i + 1] == '0' && a[i + 2] == '0' && b[i + 2] == '0') {
                    dp[i] = max(dp[i], 2 + dp[i + 3]);
                }
            }
        }
        if (a[i + 1] == '0' && b[i + 1] == '0') {
            if (a[i] == '0' || b[i] == '0') {
                dp[i] = max(dp[i], 1 + dp[i + 2]);
            }
        }
    }
    cout << dp[0] << endl;

    return 0;
}
