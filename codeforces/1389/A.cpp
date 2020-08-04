#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, L, R;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> L >> R;
        if (R < 2 * L) {
            cout << -1 << " " << -1 << endl;
        } else {
            cout << L << " " << 2 * L << endl;
        }
    }

    return 0;
}
