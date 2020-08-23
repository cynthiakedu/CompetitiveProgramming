#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
double a, b, x, y;
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Land #" << t << ": ";

        cin >> b >> a >> x >> y;
        if (a == b) {
            cout << setprecision(16) << x / 2 << " " << setprecision(16) << y / 2 << endl;
            continue;
        }
        double c = sqrt((a * a + b * b) / 2);
        cout << setprecision(16) << (b - c) / (b - a) * x << " " << setprecision(16) << (b - c) / (b - a) * y << endl;
    }

    return 0;
}
