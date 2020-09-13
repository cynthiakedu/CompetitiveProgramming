#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 998244353
const int mxN = 2e5;
int N;
ll memo[mxN + 5], p[mxN + 5], cum[mxN + 5];
ll num = 0, denom = 1;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memo[0] = 1;
    for (int i = 1; i < mxN + 5; i++) {
        memo[i] = (memo[i - 1] * 100) % MOD;
    }
    cum[0] = 1;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        cum[i] = (p[i] * cum[i - 1]) % MOD;
    }

    for (int i = 0; i < N; i++) {
        ll temp = (cum[i] * memo[N - i]) % MOD;
        num = (num + temp) % MOD;
    }
    num = (num * inv(cum[N], MOD)) % MOD;
    cout << num << endl;

    return 0;
}
