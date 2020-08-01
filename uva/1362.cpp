#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000000
string s;
ll dp[305][305];

ll solve(ll a, ll b) {
    if (b - a + 1 <= 2) return 0;
    if (b - a + 1 == 3 && s[a] == s[a + 2]) return 1;
    ll& ret = dp[a][b];
    if (ret != -1) return ret;
    if (s[a] == s[b]) ret = (ret + solve(a + 1, b - 1)) % MOD;
    for (int i = a + 2; i < b; i++) {
        ret = (ret + solve(a, i) * solve(i + 1, b)) % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s) {
        memset(dp, -1, sizeof dp);
        if (s.size() == 1) {
            cout << 1 << endl;
        } else if (s.size() <= 2 || s[0] != s[s.size() - 1]) {
            cout << 0 << endl;
        } else if (s.size()) {
            cout << solve(1, s.size() - 2) << endl;
        }
    }

    return 0;
}
