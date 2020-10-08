#include <bits/stdc++.h>
using namespace std;
int a, b;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    int g = gcd(a, b);
    a /= g;
    b /= g;

    if ((a == b - 1) || (b == a - 1)) {
        cout << "Equal" << endl;
        return 0;
    }
    if (a < b) {
        cout << "Dasha" << endl;
        return 0;
    }
    cout << "Masha" << endl;

    return 0;
}
