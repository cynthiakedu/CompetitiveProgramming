#include <bits/stdc++.h>
using namespace std;
double vp, vd, t, f, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> vp >> vd >> t >> f >> c;
    if (vp >= vd) {
        cout << 0 << endl;
        return 0;
    }
    double d = (t + (t * vp) / (vd - vp)) * vp;
    int ans = 0;
    while (d < c) {
        d += (d / vd + f + ((d / vd + f) * vp + d) / (vd - vp)) * vp;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
