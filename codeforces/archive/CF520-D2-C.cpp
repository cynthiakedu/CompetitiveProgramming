#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int N;
string S;
map<char, ll> m;
ll mx = 0, ct = 0;

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    for (auto c : S) {
        m[c]++;
        mx = max(mx, m[c]);
    }
    for (auto p : m) {
        if (p.second == mx) {
            ct++;
        }
    }
    cout << powmod(ct, N) << endl;

    return 0;
}
