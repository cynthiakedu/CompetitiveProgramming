#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll x;
int T;

void solve() {
    cin >> x;
    x = abs(x);
    for (ll i = max(1LL, (ll)floor(sqrt(2 * x)));; i++) {
        ll s = i * (i + 1) / 2;
        if (s >= x && s % 2 == x % 2) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
        if (t != T - 1) cout << endl;
    }

    return 0;
}
