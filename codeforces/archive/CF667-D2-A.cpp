#include <bits/stdc++.h>

#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;
double D, H, V, E;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> H >> V >> E;
    double h1 = V / ((D / 2) * (D / 2) * M_PI);
    if (h1 <= E) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << setprecision(16) << H / (h1 - E) << endl;
    }

    return 0;
}
