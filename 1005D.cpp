#include <bits/stdc++.h>
using namespace std;
string s;
int N;
int cum[200005];
int dp[200005];
map<int, int> lastSeen;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    N = s.size();

    for (int i = 1; i <= N; i++) {
        cum[i] = (cum[i - 1] + (s[i - 1] - '0')) % 3;
    }
    for (int i = 0; i < 3; i++)
        lastSeen[i] = N + 1;
    for (int i = N; i >= 1; i--) {
        dp[i] = dp[i + 1];
        lastSeen[cum[i]] = i;
        int l = lastSeen[cum[i - 1]];
        if (l <= N) {
            dp[i] = max(dp[i], 1 + dp[l + 1]);
        }
    }
    cout << dp[1] << endl;

    return 0;
}
