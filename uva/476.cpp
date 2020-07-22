#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
double rect[15][4];
int rCt = 0;

bool check(double x, double l, double r) {
    if (fabs(x - l) < EPS || fabs(x - r) < EPS) return false;
    if (l - x > -EPS || x - r > -EPS) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        char c;
        cin >> c;
        if (c == '*') break;
        rCt++;
        cin >> rect[rCt][0] >> rect[rCt][1] >> rect[rCt][2] >> rect[rCt][3];
    }

    double a, b;
    int num = 0;
    while ((cin >> a) && (cin >> b)) {
        if (abs(a - 9999.9) < EPS && abs(b - 9999.9) < EPS) return 0;
        num++;
        bool okAll = false;
        for (int i = 1; i <= rCt; i++) {
            if (check(a, rect[i][0], rect[i][2]) && check(b, rect[i][3], rect[i][1])) {
                okAll = true;
                cout << "Point " << num << " is contained in figure " << i << endl;
            }
        }
        if (!okAll) {
            cout << "Point " << num << " is not contained in any figure" << endl;
        }
    }

    return 0;
}
