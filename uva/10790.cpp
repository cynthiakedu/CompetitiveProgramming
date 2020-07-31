#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (true) {
        ct++;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;
        ll ans = (a * (a - 1) / 2) * (b * (b - 1) / 2);
        cout << "Case " << ct << ": " << ans << endl;
    }

    return 0;
}
