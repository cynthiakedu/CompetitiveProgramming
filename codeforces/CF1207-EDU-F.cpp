#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 500005
bool debug = false;

int arr[MXN], dp[805][805], Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> Q;
    for (int i = 0, t, x, y; i < Q; i++) {
        cin >> t >> x >> y;
        if (t == 1) {
            for (int j = 1; j <= sqrt(500000); j++) {
                dp[j][x % j] += y;
            }
            arr[x] += y;
        } else {
            if (x <= sqrt(500000)) {
                cout << dp[x][y] << "\n";
            } else {
                int ans = 0;
                for (int j = y; j <= 500000; j += x) {
                    ans += arr[j];
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
