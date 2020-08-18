#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll l, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r;
    for (int i = 63; i >= 0; i--) {
        int d1 = (l >> i) & 1;
        int d2 = (r >> i) & 1;
        if (d1 != d2) {
            cout << ((1LL << (i + 1)) - 1) << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}
