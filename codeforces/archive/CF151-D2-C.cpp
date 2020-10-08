#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<ll> primes;
const int mxN = 4e6 + 5;
bool vis[mxN];
ll q;

vector<ll> factorize(ll n) {
    vector<ll> v;
    for (ll d = 1, i = 2; i * i <= n && v.size() <= 3; i += d, d = 2) {
        while (n % i == 0) {
            n /= i;
            v.push_back(i);
        }
    }
    if (n > 1) v.push_back(n);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    vector<ll> v = factorize(q);

    if (v.size() <= 1) {
        cout << "1\n0\n";
    } else if (v.size() == 2) {
        cout << "2\n";
    } else {
        cout << "1\n"
             << v[0] * v[1] << "\n";
    }

    return 0;
}
