#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ii pair<int, int>
ll N, H;

bool can(ll x) {
    ll h = min(x, H);
    ll y = x - h, ret = h * (h + 1) / 2;
    ret += y * h;
    ret += (y % 2 == 1 ? (y / 2) * (y / 2 + 1) : (y / 2) * (y / 2));
    return ret >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;

    ll l = 1, r = 3 * sqrt(N);
    while (l < r) {
        ll m = (l + r) / 2;
        bool ok = can(m);
        if (ok) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}
