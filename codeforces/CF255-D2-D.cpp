#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll n, x, y, c;

ll ct(ll a, ll b, ll t) {
    b = min(b, t + 1);
    a = min(a, t + 1);
    if (b <= t + 2 - a) {
        return a * b;
    }
    ll ret = (t + 2 - a) * a;
    b -= (t + 2 - a);
    b = min(a - 1, b);
    ret += (a - 1 + a - b) * (b) / 2;
    return ret;
}

bool check(ll t) {
    ll ret = 0;
    ret += ct(x, n + 1 - y, t);
    ret += ct(n + 1 - x, n + 1 - y, t);
    ret += ct(y, x, t);
    ret += ct(y, n + 1 - x, t);
    ret -= min(t + 1, x) + min(t + 1, n + 1 - x);
    ret -= min(t + 1, y) + min(t + 1, n + 1 - y);
    ret += 1;
    return ret >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y >> c;
    check(1);

    ll l = 0, r = n * n;
    while (l < r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}
