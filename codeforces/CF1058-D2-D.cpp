#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, M, n, m, K, k;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    if (K == 1) {
        cout << "NO" << endl;
        return 0;
    }
    n = N;
    m = M;
    k = K;
    ll g = gcd(N * M, K);
    ll g1 = gcd(g, n);
    n /= g1;
    m /= (g / g1);
    k /= g;

    if (k == 1) {
        cout << "YES" << endl;

        if (n < N) {
            cout << 0 << " " << 0 << endl;
            cout << 2 * n << " " << 0 << endl;
            cout << 2 * n << " " << m << endl;
        } else {
            cout << 0 << " " << 0 << endl;
            cout << n << " " << 0 << endl;
            cout << 0 << " " << 2 * m << endl;
        }
    } else if (k == 2) {
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << m << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
