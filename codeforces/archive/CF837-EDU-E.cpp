#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e6;
vector<ll> primes;
bool vis[mxN + 5];
ll a, b;
map<ll, ll> m;
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < mxN + 5; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < mxN + 5; j += i) {
            vis[j] = true;
        }
    }

    cin >> a >> b;
    ll a1 = a;
    for (ll x : primes) {
        while (a1 % x == 0) {
            a1 /= x;
            m[x]++;
        }
    }
    if (a1 > 1) m[a1]++;

    while (true) {
        ll p = -1, amt = LLONG_MAX;
        for (auto x : m) {
            if (x.second == 0) continue;
            ll temp = b % x.first;
            if (temp < amt) {
                p = x.first;
                amt = temp;
            }
        }
        if (p == -1 || b == 0) {
            ans += b;
            break;
        }
        ans += amt;
        m[p]--;
        b /= p;
    }
    cout << ans << endl;

    return 0;
}
