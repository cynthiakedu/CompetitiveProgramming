#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, d;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;

    ll x1 = a * b * c - a * a * d, y1 = c;
    ll x2 = a * b * d - b * b * c, y2 = d;

    if ((ll)x1 * (ll)y2 < (ll)x2 * (ll)y1) {
        swap(x1, x2);
        swap(y1, y2);
    }
    y1 *= a * b;
    ll g = gcd(x1, y1);
    cout << x1 / g << "/" << y1 / g << endl;

    return 0;
}
