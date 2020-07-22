#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r;
    if (r - l + 1 <= 2) {
        cout << -1 << endl;
        return 0;
    }
    if (l % 2 == 0 && r - l + 1 >= 3) {
        cout << l << " " << l + 1 << " " << l + 2 << endl;
        return 0;
    }
    if (l % 2 == 1 && r - l + 1 >= 4) {
        cout << l + 1 << " " << l + 2 << " " << l + 3 << endl;
        return 0;
    }
    if (gcd(l, l + 2) > 1) {
        cout << l << " " << l + 1 << " " << l + 2 << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
