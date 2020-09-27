#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 2000005
#define MOD 998244353
bool debug = false;
ll N, M, memo[2 * MXN], cum, nxt, q;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memo[0] = 1;
    for (ll i = 1; i < 2 * MXN; i++) memo[i] = (memo[i - 1] * i) % MOD;

    cin >> N >> M;
    ll a = inv(memo[M], MOD), b = inv(M + 1, MOD), c = N + M + 1;
    for (ll i = 1; i <= N; i++) {
        q = (((a * inv(memo[i], MOD)) % MOD) * memo[M + i]) % MOD;

        nxt = (cum + (((q * c) % MOD) * b) % MOD) % MOD;
        nxt = (((nxt * M) % MOD) * inv(i, MOD)) % MOD;
        cum = (cum + nxt) % MOD;
        // cout << "dp " << i << " " << nxt << endl;
    }
    nxt = (((nxt * memo[M - 1]) % MOD) * memo[N]) % MOD;
    nxt = (nxt * inv(memo[M - 1 + N], MOD)) % MOD;
    cout << nxt << "\n";
    return 0;
}
