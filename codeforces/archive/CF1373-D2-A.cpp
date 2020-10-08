#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll T, a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> a >> b >> c;
        ll x = -1, y = -1;
        if (a < c) x = 1;
        if (a * b > c) y = b;
        cout << x << " " << y << endl;
    }

    return 0;
}
