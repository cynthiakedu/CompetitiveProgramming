#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
double x1, y11, x2, y2, x3, y3, x4, y4;

bool isSame(int a, int b, int c, int d) {
    return fabs(a - c) < EPS && fabs(b - d) < EPS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> x1) && (cin >> y11) && (cin >> x2) && (cin >> y2) && (cin >> x3) && (cin >> y3) && (cin >> x4) && (cin >> y4)) {
        double x, y;
        if (isSame(x1, y11, x3, y3)) {
            x = x2 + x4 - x3, y = y2 + y4 - y3;
        } else if (isSame(x1, y11, x4, y4)) {
            x = x2 + x3 - x1, y = y2 + y3 - y11;
        } else if (isSame(x2, y2, x4, y4)) {
            x = x1 + x3 - x2, y = y11 + y3 - y2;
        } else if (isSame(x2, y2, x3, y3)) {
            x = x1 + x4 - x2, y = y11 + y4 - y2;
        }
        x = round(1000 * x) / 1000, y = round(1000 * y) / 1000;
        cout << fixed << setprecision(3) << x << " " << y << endl;
    }

    return 0;
}
