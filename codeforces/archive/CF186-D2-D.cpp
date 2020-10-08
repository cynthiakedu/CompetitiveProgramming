#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
double S, a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    cin >> a >> b >> c;
    if (a + b + c == 0) {
        cout << setprecision(16) << S << " " << 0.0 << " " << 0.0 << endl;
        return 0;
    }
    double t = S / (a + b + c);

    cout << setprecision(16) << a * t << " " << setprecision(16) << b * t << " " << setprecision(16) << c * t << endl;

    return 0;
}
