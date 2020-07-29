#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007

map<ll, ll> memo;

ll fib(ll x) {
    if (x == 0 || x == 1) return 1;
    if (x == 2) return 2;
    if (memo.count(x) > 0) return memo[x];
    if (x % 2 == 0) {
        ll a = fib((x - 2) / 2), b = fib(x / 2);
        ll ret = ((a * a) % MOD + (b * b) % MOD) % MOD;
        return memo[x] = ret;
    } else {
        ll k = x / 2;
        ll ret = ((fib(k) * fib(k + 1)) % MOD + (fib(k - 1) * fib(k)) % MOD) % MOD;
        return memo[x] = ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
