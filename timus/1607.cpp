#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d;
    x = a, y = c;

    if (c < a) {
        cout << a << endl;
        return 0;
    }
    for (int i = 0; i < 200005; i++) {
        if (i % 2 == 0) {
            if (x + b > y) {
                cout << y << endl;
                return 0;
            }
            x += b;
        } else {
            if (y - d < x) {
                cout << x << endl;
                return 0;
            }
            y -= d;
        }
    }

    return 0;
}
