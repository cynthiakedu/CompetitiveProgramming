#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int N, M;
int m[20];
ll dp[1 << 19][105];

ll powmod(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2, mod);
    return (((z * z) % mod) * (b % 2 == 1 ? a : 1)) % mod;
}

ll solve(int state, int modulo) {
    ll ct = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (state & (1 << i)) {
            ct++;
        }
    }
    if (ct == 0) {
        return modulo == 0 ? 1 : 0;
    }
    if (dp[state][modulo] != -1) return dp[state][modulo];

    ll& ret = dp[state][modulo] = 0;
    bool seen[10] = {};

    for (int i = N - 1; i >= 0; i--) {
        if (ct == N && s[i] == '0') continue;

        if (state & (1 << i)) {
            if (seen[s[i] - '0']) continue;
            seen[s[i] - '0'] = true;
            ret += solve(state ^ (1 << i), (modulo + (s[i] - '0') * powmod(10LL, ct - 1, M)) % M);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> s >> M;
    N = s.size();
    m[0] = 1;

    cout << solve((1 << N) - 1, 0) << endl;

    return 0;
}
