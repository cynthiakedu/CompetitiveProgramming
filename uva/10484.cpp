#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, D;

vector<ll> primes;
bool vis[100005];

ll p(ll a, ll b) {
    if (b == 0) return 1;
    ll z = p(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
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
    while (true) {
        cin >> N >> D;
        if (N == 0 && D == 0) return 0;
        ll ans = 1;
        for (auto x : primes) {
            ll ct1 = 0, ct2 = 0;
            ll idx = 1;
            while (N >= p(x, idx)) {
                ct1 += N / p(x, idx);
                idx++;
            }
            while (D % x == 0) {
                D /= x;
                ct2++;
            }

            ans *= max(ct1 - ct2 + 1, 0LL);
        }
        if (D > 1) ans = 0;
        cout << ans << endl;
    }

    return 0;
}
