#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
double a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> a >> b;
        if (b == 0) {
            cout << 1.0 << endl;
            continue;
        }
        if (a >= 4 * b) {
            cout << setprecision(16) << (a - b) / a << endl;
        } else {
            if (a == 0) {
                cout << setprecision(15) << 1.0 / 2 << endl;
            } else {
                double t = 2 * a * b - ((b - a / 4 + b)) * a / 2;
                cout << setprecision(16) << t / (2 * a * b) << endl;
            }
        }
    }

    return 0;
}
