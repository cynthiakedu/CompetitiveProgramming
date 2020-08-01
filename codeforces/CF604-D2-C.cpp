#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
string s;
int lst[2];
int dp[100005][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        int num = s[i - 1] - '0';
        lst[num] = i;
        int lst1 = lst[1 - num];
        dp[i][0] = dp[lst1][0] + 1;
        dp[i][1] = dp[lst1][1];
        dp[i][2] = dp[lst1][2];
        if (lst1 < i - 1) {
            dp[i][1 + num] = 1;
        }
    }
    int lst0 = lst[0], lst1 = lst[1];
    int ans = 0;
    ans = max(ans, dp[lst0][0] + (dp[lst0][1] && dp[lst0][2] ? 2 : 0));
    ans = max(ans, dp[lst1][0] + (dp[lst1][1] && dp[lst1][2] ? 2 : 0));
    cout << ans << endl;
    return 0;
}
