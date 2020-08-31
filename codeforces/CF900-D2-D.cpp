#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll x, y;
vector<int> primes;
bool vis[100005];

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 100005; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 100005; j += i) {
            vis[j] = true;
        }
    }

    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    ll y1 = y;
    vector<int> yp;
    for (auto p : primes) {
        if (y1 % p == 0) yp.push_back(p);
        while (y1 % p == 0) y1 /= p;
    }
    if (y1 > 1) yp.push_back(y1);

    ll ans = 0;
    for (int i = 0; i < (1 << yp.size()); i++) {
        ll num = 1, ct = 0;
        for (int j = 0; j < yp.size(); j++) {
            if (i & (1 << j)) {
                ct++;
                num *= yp[j];
            }
        }
        ans = (ans + (ct % 2 == 1 ? -1 : 1) * powmod(2, y / num - 1) + 2 * MOD) % MOD;
    }

    cout << ans % MOD << endl;
    return 0;
}
