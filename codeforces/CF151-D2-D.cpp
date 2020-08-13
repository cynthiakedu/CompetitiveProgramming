#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll N, K, M;

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    if (N <= K - 1 || K == 1) {
        cout << powmod(M, N) << endl;
    } else if (N == K) {
        cout << powmod(M, (N + 1) / 2) << endl;
    } else {
        if (K % 2 == 0) {
            cout << M << endl;
        } else {
            cout << (M * M) % MOD << endl;
        }
    }

    return 0;
}
