#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int N;

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    ll a = powmod(3, 3 * N);
    ll b = powmod(7, N);
    cout << ((a - b + MOD) % MOD) << endl;

    return 0;
}
