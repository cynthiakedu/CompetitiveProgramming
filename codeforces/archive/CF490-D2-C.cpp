#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int a, b;
ll A[1000005], B[1000005];

ll pmod(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll z = pmod(a, b / 2, m);
    return (((z * z) % m) * (b % 2 == 1 ? a : 1)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cin >> a >> b;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0)
            A[i] = (s[0] - '0') % a;
        else
            A[i] = (10 * (A[i - 1]) + (s[i] - '0')) % a;
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (i == s.size() - 1)
            B[i] = (s[i] - '0') % b;
        else {
            B[i] = (pmod(10, s.size() - i - 1, b) * (s[i] - '0') + B[i + 1]) % b;
        }
    }

    for (int i = s.size() - 1; i >= 1; i--) {
        if (s[i] == '0') continue;
        if (A[i - 1] == 0 && B[i] == 0) {
            ll lb = s.size() - i;
            cout << "YES" << endl;
            cout << s.substr(0, s.size() - lb) << endl;
            cout << s.substr(i, lb) << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
