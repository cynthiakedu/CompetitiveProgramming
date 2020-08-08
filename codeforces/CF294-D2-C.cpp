#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll N, M, arr[1005], N2;
vector<int> v;
ll fact[1005];

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (ll i = 1; i < 1005; i++) fact[i] = (fact[i - 1] * i) % MOD;

    cin >> N >> M;
    arr[0] = arr[N + 1] = 1;
    for (int i = 0, x; i < M; i++) {
        cin >> x;
        arr[x] = 1;
    }
    int idx = 0;
    while (idx <= N) {
        int j = idx + 1;
        while (j <= N + 1 && arr[j] == 0) j++;
        v.push_back(j - idx - 1);
        idx = j;
    }
    ll ans = fact[N - M];
    for (auto x : v) {
        ans = (ans * inv(fact[x], MOD)) % MOD;
    }
    for (int i = 1; i < v.size() - 1; i++) {
        ans = (ans * powmod(2, v[i] - 1)) % MOD;
    }
    cout << ans << endl;

    return 0;
}
