#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll B, P, M;

ll powmod(ll x, ll y) {
    if (y == 0) return 1;
    ll z = powmod(x, y / 2);
    return (((z * z) % M) * (y % 2 == 1 ? x : 1)) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> B) && (cin >> P) && (cin >> M)) {
        cout << powmod(B, P) << endl;
    }

    return 0;
}
