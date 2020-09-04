#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll K, N;
set<int> S;
vector<ii> v;
int lst = INT_MAX;
int arr[200005][2];
ll fact[200005];
ll ans = 0;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for (ll i = 1; i < 200005; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    cin >> N >> K;
    for (int i = 1, l, r; i <= N; i++) {
        cin >> l >> r;
        v.push_back({l - 1, -i});
        v.push_back({r, i});
        lst = min(l, lst);
    }
    sort(v.begin(), v.end());

    int idx = 0;
    while (idx < (int)v.size()) {
        int x = v[idx].first;
        ll ct = (ll)S.size();
        if (ct >= K) {
            ll tmp = (((fact[ct] * inv(fact[K], MOD)) % MOD) * inv(fact[ct - K], MOD)) % MOD;
            tmp = (tmp * (v[idx].first - lst)) % MOD;
            ans = (ans + tmp) % MOD;
        }
        int j = idx;
        while (j < (int)v.size() && v[j].first == v[idx].first) {
            if (v[j].second < 0) {
                S.insert(-v[j].second);
            } else {
                S.erase(v[j].second);
            }
            j++;
        }
        lst = v[idx].first;
        idx = j;
    }
    cout << ans % MOD << endl;

    return 0;
}
