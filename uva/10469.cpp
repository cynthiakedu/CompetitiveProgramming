#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> a) && (cin >> b)) {
        long long ans = 0;
        for (int i = 0; i < 32; i++) {
            long long x = (a & (ll)(1 << i));
            long long y = (b & (ll)(1 << i));
            if (x ^ y) {
                ans += (ll)(1 << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
