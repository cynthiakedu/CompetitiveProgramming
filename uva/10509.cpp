#include <bits/stdc++.h>
using namespace std;
double n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) return 0;
        int a = (int)floor(cbrt(n));
        double dx = (n - 1.0 * a * a * a) / (3.0 * a * a);
        double res = a + dx;
        cout << fixed << setprecision(4) << res << endl;
    }

    return 0;
}
