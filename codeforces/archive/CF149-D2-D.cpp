#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
string s;
ll dp[705][705][3][3];

ll solve(int l, int r, int cl, int cr) {
    if (r < l) return 1;
    if (dp[l][r][cl][cr] != -1) return dp[l][r][cl][cr];
    int ct = 0, idx = l;
    for (; idx <= r; idx++) {
        if (s[idx] == '(')
            ct++;
        else
            ct--;
        if (ct == 0) break;
    }
    ll ret = 0;

    for (int a = 0; a < 3; a++) {
        if (cl > 0 && a == cl) continue;
        for (int b = 0; b < 3; b++) {
            if (idx == r && cr > 0 && b == cr) continue;
            if (!a && !b) continue;
            if (a && b) continue;
            ll x = solve(l + 1, idx - 1, a, b);
            ret = (ret + x * solve(idx + 1, r, b, cr)) % MOD;
        }
    }
    return dp[l][r][cl][cr] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << solve(0, s.size() - 1, 0, 0) % MOD << endl;

    return 0;
}
