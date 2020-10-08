#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 998244353
int N;
ll arr[505];
map<ll, ll> m2;
vector<int> primes[505];
ll ct[505];
map<ll, ll> m;
ll ans = 1;

ll powcd(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powcd(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        m2[arr[i]]++;
    }
    N = 0;
    for (auto p : m2) {
        N++;
        arr[N] = p.first;
        ct[N] = p.second;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 4; j >= 2; j--) {
            ll x = (ll)round(pow((double)arr[i], 1.0 / j));
            if (powcd(x, j) == arr[i]) {
                primes[i].push_back(x);
                ct[i] *= j;
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (primes[i].size()) continue;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            ll g = gcd(arr[i], arr[j]);
            if (g > 1 && g < arr[i]) {
                primes[i].push_back(g);
                primes[i].push_back(arr[i] / g);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (primes[i].size() == 0) {
            ans = (ans * (ct[i] + 1) * (ct[i] + 1)) % MOD;
        } else if (primes[i].size() == 1) {
            m[primes[i][0]] += ct[i];
        } else {
            m[primes[i][0]] += ct[i];
            m[primes[i][1]] += ct[i];
        }
    }
    for (auto p : m) {
        ans = (ans * (p.second + 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}
