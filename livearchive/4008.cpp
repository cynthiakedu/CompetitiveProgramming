#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e6;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

ll m2[mxN + 5], m5[mxN + 5], c2[mxN + 5], c5[mxN + 5];
ll getMod(ll mod2, ll mod5) {
    for (int i = 1; i <= 9; i++) {
        if (i % 2 == mod2 % 2 && i % 5 == mod5 % 5) return i;
    }
    return 0;
}

ll powmod(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2, m);
    return (((z * z) % m) * (b % 2 == 1 ? a : 1)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    m2[1] = 1;
    m5[1] = 1;

    for (ll i = 2; i < mxN; i++) {
        ll i1 = i;
        while (i1 % 2 == 0) {
            i1 /= 2;
            c2[i]++;
        }
        while (i1 % 5 == 0) {
            i1 /= 5;
            c5[i]++;
        }
        c2[i] += c2[i - 1];
        c5[i] += c5[i - 1];

        m2[i] = (m2[i - 1] * i1) % 2;
        m5[i] = (m5[i - 1] * i1) % 5;
    }

    string s;
    while (cin >> s) {
        int S[26] = {};
        for (auto c : s) {
            S[c - 'a']++;
        }
        vector<int> v;
        ll num2 = c2[s.size()], num5 = c5[s.size()];
        ll x2 = m2[s.size()], x5 = m5[s.size()];
        for (int i = 0; i < 26; i++) {
            if (S[i]) {
                v.push_back(S[i]);
                num2 -= c2[S[i]];
                num5 -= c5[S[i]];
                x2 = (x2 * inv(m2[S[i]], 2)) % 2;
                x5 = (x5 * inv(m5[S[i]], 5)) % 5;
            }
        }
        ll g = min(num2, num5);
        num2 -= g;
        num5 -= g;
        ll mod2 = num2 > 0 ? 0 : (x2 * powmod(5, num5, 2)) % 5;
        ll mod5 = num5 > 0 ? 0 : (x5 * powmod(2, num2, 5)) % 5;
        ll x = getMod(mod2, mod5);
        cout << x << endl;
    }

    return 0;
}
