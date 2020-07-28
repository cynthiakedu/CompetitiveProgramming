#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int T;
ll A, B, N;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return ((((z * z) % MOD) * (b == 1 ? a : 1)) % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B >> N;
    }

    return 0;
}
