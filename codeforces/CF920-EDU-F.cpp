#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3e5;
int N, M;

ll fwt[mxN + 5];

ll rsq(int b) {
    ll ret = 0;
    for (; b >= 1; b -= b * (-b)) ret += fwt[b];
}
ll rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}

void adjust(int k, ll v) {
    for (; k < mxN + 5; k += k & (-k)) fwt[k] += v;
}

ll dp[1000005];
vector<ll> primes[1000005];
bool vis[1000005];

int right[mxN + 5], left[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 2; i < 1000005; i++) {
        if (vis[i]) continue;
        for (ll j = i; j < 1000005; j += i) {
            primes[j].push_back(i);
            vis[j] = true;
        }
    }
    for (int i = 1; i < mxN + 5; i++) {
        right[i] = i + 1;
        left[i] = i - 1;
    }

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        adjust(1, x);
    }
    dp[1] = 1;
    dp[2] = 2;
    for (ll i = 1; i < 1000005; i++) {
        vector<ll> v;
        ll i1 = i;
        for (ll x : primes[i]) {
            ll ct = 0;
            while (i1 % x == 0) {
                i1 /= x;
                ct++;
            }
            v.push_back(ct);
        }
        ll num = 1;
        for (auto x : v) num *= (x + 1);
        dp[i] = num;
    }

    for (int i = 0; i < M; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            int idx = l;
            while (idx <= r) {
                ll curr = rsq(idx, idx);
                ll curr1 = dp[curr];
                adjust()
            }
        } else {
            cout << rsq(l, r) << "\n";
        }
    }

    return 0;
}
