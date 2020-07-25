#include <bits/stdc++.h>
using namespace std;

int m, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> m) && (cin >> n)) {
        if (m == 1 && n == 1) {
            return 0;
        }
        int al = 0, bl = 1, ar = 1, br = 0;
        while (true) {
            int am = al + ar, bm = bl + br;

            if (am == m && bm == n) {
                cout << endl;
                break;
            }
            if (am * n < bm * m) {
                cout << "R";
                al = am, bl = bm;
            } else {
                cout << "L";
                ar = am, br = bm;
            }
        }
    }

    return 0;
}
