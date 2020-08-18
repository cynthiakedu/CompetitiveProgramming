#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll a00, a01, a10, a11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a00 >> a01 >> a10 >> a11;
    if (!a00 && !a01 && !a10 && !a11) {
        cout << 0 << endl;
        return 0;
    }
    ll num0 = floor(sqrt(2 * a00));
    ll num1 = floor(sqrt(2 * a11));
    if ((ll)num0 * (num0 + 1) / 2 != a00) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a00 != 0) {
        num0++;
    } else if (a01 || a10) {
        num0 = 1;
    }
    if ((ll)num1 * (num1 + 1) / 2 != a11) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (num1 != 0)
        num1++;
    else if (a01 || a10)
        num1 = 1;
    ll total = (ll)(num0 + num1) * (num0 + num1 - 1) / 2;
    if (total != a10 + a01 + a00 + a11) {
        cout << "Impossible" << endl;
        return 0;
    }
    // cout << "num 0 1 " << num0 << " " << num1 << endl;
    string t;
    for (ll i = num0; i >= 1; i--) {
        ll ct = a01 / i;
        a01 -= ct * i;
        num1 -= ct;
        for (ll j = 0; j < ct; j++) {
            t += "1";
        }
        t += "0";
    }
    for (ll j = 0; j < num1; j++) {
        t += "1";
    }
    reverse(t.begin(), t.end());
    cout << t << endl;

    return 0;
}
