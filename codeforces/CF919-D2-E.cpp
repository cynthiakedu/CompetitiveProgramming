#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e6;
ll a, b, p, x;
ll powers[mxN + 10];
vector<ll> v;
ll ans = 0;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> p >> x;
    powers[0] = 1;
    for (int i = 1; i <= p - 2; i++) powers[i] = (powers[i - 1] * a) % p;

    for (ll i = 0; i <= p - 2; i++) {
        ll nmp = (b * inv(powers[i], p)) % p;
        ll n = i + (p - 1) * (i - nmp);
        n = (n + p * (p - 1)) % (p * (p - 1));
        v.push_back(n);
    }
    ll num = x / (p * (p - 1));
    ll rem = x % (p * (p - 1));
    ans += num * v.size();
    sort(v.begin(), v.end());
    ll pos = (ll)(upper_bound(v.begin(), v.end(), rem) - v.begin());
    ans += pos;
    cout << ans << endl;
    return 0;
}
