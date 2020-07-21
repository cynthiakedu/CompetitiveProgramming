#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, M, A, D;
ll arr[5];

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}
ll ct(ll x) {
    ll ret = 0;
    for (int i = 0; i < (1 << 5); i++) {
        ll prod = 1, amt = 0, ad = x;
        for (int j = 0; j < 5; j++) {
            if (i & (1 << j)) {
                ad /= arr[j] / gcd(prod, arr[j]);
                prod = prod * arr[j] / gcd(prod, arr[j]);
                amt += 1;
            }
        }
        ret += ad * (amt % 2 == 0 ? 1 : -1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> A >> D;
        for (ll i = 0; i < 5; i++) arr[i] = A + D * i;
        cout << ct(M) - ct(N - 1) << endl;
    }

    return 0;
}
