#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll a, b, N, low, high;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    ll g = gcd(a, b);
    vector<ll> v;
    for (ll i = 1; i <= sqrt(g); i++) {
        if (g % i == 0) {
            v.push_back(i);
            v.push_back(g / i);
        }
    }
    sort(v.begin(), v.end());

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> low >> high;
        int pos1 = (int)(lower_bound(v.begin(), v.end(), low) - v.begin());
        int pos2 = (int)(upper_bound(v.begin(), v.end(), high) - v.begin());
        if (pos1 == pos2) {
            cout << -1 << endl;
        } else {
            cout << v[pos2 - 1] << endl;
        }
    }

    return 0;
}
