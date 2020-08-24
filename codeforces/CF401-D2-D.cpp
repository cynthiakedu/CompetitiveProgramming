#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int N, M;
int m[20];
ll dp[1 << 19][105];

ll solve(int state, int modulo) {
    if (idx == N) {
        return modulo == 0 ? 1 : 0;
    }
    if (dp[state][idx] != -1) return dp[state][idx];

    ll& ret = dp[state][idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> M;
    N = s.size();
    m[0] = 1;
    for (int i = 1; i <= 20; i++) m[i] = (m[i - 1] * 10) % M;

    return 0;
}
