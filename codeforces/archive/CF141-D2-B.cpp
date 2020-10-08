#include <bits/stdc++.h>
using namespace std;
int A, X, Y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> X >> Y;
    int d = Y / A;
    int r = Y % A;
    if (r == 0) {
        cout << -1 << endl;
        return 0;
    }
    int prev = d == 0 ? 0 : 1 + 3 * ((d - 1) / 2) + (d % 2 == 0 ? 1 : 0);
    if (d == 0 || d % 2 == 1) {
        int w = (A + 1) / 2;
        if (-w < X && X < w) {
            cout << prev + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (-A < X && X < 0) {
            cout << prev + 1 << endl;
        } else if (0 < X && X < A) {
            cout << prev + 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
