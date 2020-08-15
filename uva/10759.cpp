#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, X;
ll dp[27][155];

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    ll z = pow(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> N >> X;
        if (N == 0 && X == 0) return 0;
        memset(dp, 0, sizeof dp);

        for (int n = 0; n <= N; n++) {
            for (int x = 0; x <= N * 6; x++) {
                if (n == 0) {
                    dp[n][x] = x == 0 ? 1 : 0;
                    continue;
                }
                for (int i = 1; i <= 6; i++) {
                    if (i <= x) {
                        dp[n][x] += dp[n - 1][x - i];
                    }
                }
            }
        }
        ll s = 0;
        for (int i = X; i <= 6 * N; i++) {
            s += dp[N][i];
        }
        ll d = pow(6, N);
        ll g = gcd(s, d);
        if (s == 0) {
            cout << 0 << endl;
        } else if (s / g == 1 && d / g == 1) {
            cout << 1 << endl;
        } else {
            cout << s / g << "/" << d / g << endl;
        }
    }

    return 0;
}
