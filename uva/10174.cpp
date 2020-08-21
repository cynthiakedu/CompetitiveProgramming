#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
vector<ll> v;

ll ct(ll x) {
    if (x == -1) return 0;
    ll amt = x / 4;
    return amt + (x % 4 >= 2 ? 1 : 0);
}

void solve() {
    if (v.size() == 1) {
        ll x = v[0];
        if (abs(x) % 4 == 2) {
            cout << "Bachelor Number." << endl;
            return;
        }
        ll a, b;
        ll amt = x > 0 ? 1 : -1;

        if (abs(x) % 2 == 1) {
            a = (abs(x) + amt) / 2, b = (abs(x) - amt) / 2;
        } else {
            a = (abs(x) / 2 + amt * 2) / 2, b = (abs(x) / 2 - amt * 2) / 2;
        }
        cout << a << " " << b << endl;
        return;
    }
    ll x = v[0], y = v[1];
    cout << ct(y) - ct(x - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (getline(cin, s)) {
        v.clear();
        istringstream iss(s);
        ll x;
        while (iss >> x) v.push_back(x);
        solve();
    }

    return 0;
}
