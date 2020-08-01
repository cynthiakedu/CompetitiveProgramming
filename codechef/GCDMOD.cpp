#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MOD 1000000007
int T;
ll A, B, N;

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return ((((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD);
}

vector<int> primes;
bool vis[100005];

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
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B >> N;
        ll diff = A - B;
        if (diff < 0) diff *= -1;
        ll ans = 1;
        for (auto p : primes) {
            ll ct1 = 0, ct2 = 0;
            while (B > 0 && B % p == 0) {
                B /= p;
                ct1++;
            }
            while (diff > 0 && diff % p == 0) {
                diff /= p;
                ct2++;
            }
            ct1 = (ct1 * N) + (p == 2 ? 1 : 0);
            ct2 = diff == 0 ? INT_MAX : ct2;
            ans = (ans * powmod(p, min(ct1, ct2))) % MOD;
        }
        if (B == diff) {
            ans = (ans * powmod(B, N)) % MOD;
        }
        cout << ans % MOD << endl;
    }

    return 0;
}
