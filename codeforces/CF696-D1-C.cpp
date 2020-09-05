#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 1e5;
int N;
ll nums[mxN + 5];
bool isEven = false;
// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        if (nums[i] % 2 == 0) isEven = true;
    }

    ll q = 2, p = 2, tmp = 2;
    for (int i = 1; i <= N; i++) {
        ll x = nums[i];
        q = powmod(q, x);
        tmp = powmod(tmp, x);
    }
    q = (q * inv(2, MOD)) % MOD;
    tmp = (tmp * inv(isEven ? 4 : 2, MOD)) % MOD;

    ll p2 = (tmp - 1 + MOD) % MOD;
    p2 = (p2 * inv(3, MOD)) % MOD;
    p2 = (p2 * (isEven ? 1 : 2)) % MOD;

    p = (tmp - p2 + 2 * MOD) % MOD;
    p = (p - (isEven ? 0 : 1) + MOD) % MOD;

    cout << p << "/" << q << endl;

    return 0;
}
