#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll n;

ll dig(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (ll x = max(0LL, (ll)sqrt(n) - 200LL); x <= sqrt(n); x++) {
        if (x * (x + dig(x)) == n) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
