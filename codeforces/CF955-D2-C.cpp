#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = true;
int Q;
ll L, R;

ll ct(ll a, ll b, ll p) {
    ll r = floor(pow((double)b, 1.0 / p));
    ll l = floor(pow((double)(a - 1), 1.0 / p));
    return r - l;
}

vector<int> primes;
bool vis[65];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < 65; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 65; j += i) {
            vis[j] = true;
        }
    }

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> L >> R;
        ll ans = 0;
        for (int i = 0; i < (1 << 18); i++) {
            ll tmp = 0, mult = 1, amt = 0;
            for (int j = 0; j < 18; j++) {
                if (i & (1 << j)) {
                    mult *= primes[j];
                    amt++;
                }
            }
            if (amt == 0) continue;
            tmp = ct(L, R, mult) * (amt % 2 == 1 ? 1 : -1);
            if (debug) cout << "temp " << i << " " << tmp << endl;
            ans += tmp;
        }
    }

    return 0;
}
