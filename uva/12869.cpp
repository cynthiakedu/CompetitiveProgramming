#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll low, high;

ll ct(ll num, ll x) {
    ll ret = 0;
    while (num >= x) {
        ret += num / x;
        num /= x;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> low >> high;
        if (!low && !high) return 0;
        ll a = min(ct(low, 2), ct(low, 5));
        ll b = min(ct(high, 2), ct(high, 5));
        cout << b - a + 1 << endl;
    }

    return 0;
}
