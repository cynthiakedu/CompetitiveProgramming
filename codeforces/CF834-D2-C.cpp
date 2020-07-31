#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ii pair<int, int>
int N;
ll a, b;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        bool ok = true;
        cin >> a >> b;
        ll x = floor(cbrt(a * b));
        cout << "ct r " << cbrt(a * b) << endl;
        ll g = gcd(a, b);
        cout << "x " << x << endl;
        cout << "g " << g << endl;
        cout << "x3 " << x * x * x << endl;
        cout << "a b " << a * b << endl;
        if (x * x * x != a * b) {
            ok = false;
            cout << "here 1" << endl;
        }
        if ((g * g) % a != 0 || (g * g) % b != 0) {
            ok = false;
            cout << "here 2" << endl;
        }
        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
