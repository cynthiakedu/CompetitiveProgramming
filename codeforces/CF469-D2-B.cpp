#include <bits/stdc++.h>
using namespace std;
int p, q, l, r, A[55][2], B[55][2];
bool ok[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> q >> l >> r;
    for (int i = 0; i < p; i++) {
        cin >> A[i][0] >> A[i][1];
    }
    for (int i = 0; i < q; i++) {
        cin >> B[i][0] >> B[i][1];
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            int a = A[i][0], b = A[i][1], c = B[j][0], d = B[j][1];
            if (c <= b) {
                int l1 = max(a - (d - c), c), r1 = b;
                for (int k = l; k <= r; k++) {
                    if (l1 - c <= k && k <= r1 - c) ok[k] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (ok[i]) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
