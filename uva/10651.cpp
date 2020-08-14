#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
string s;
int dp[(1 << 12)];

int solve(int x) {
    if (dp[x] != -1) {
        return dp[x];
    }
    int ct = 0;
    for (int i = 0; i < 12; i++) {
        if (x & (1 << i)) {
            ct++;
        }
    }
    dp[x] = ct;
    for (int i = 0; i <= 9; i++) {
        int a = x & (1 << i);
        int b = x & (1 << (i + 1));
        int c = x & (1 << (i + 2));
        if (a && b && !c) {
            int y = x;
            y ^= (1 << i) + (1 << (i + 1));
            y |= 1 << (i + 2);
            dp[x] = min(dp[x], solve(y));
        } else if (!a && b && c) {
            int y = x;
            y ^= (1 << (i + 1)) + (1 << (i + 2));
            y |= 1 << (i);
            dp[x] = min(dp[x], solve(y));
        }
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> s;
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'o') {
                x += (1 << i);
            }
        }
        cout << solve(x) << endl;
    }

    return 0;
}
