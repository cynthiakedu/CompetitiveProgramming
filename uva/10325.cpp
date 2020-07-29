#include <bits/stdc++.h>
using namespace std;
int N, M, arr[20];

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> N) && (cin >> M)) {
        int ans = 0;
        for (int i = 0; i < M; i++) cin >> arr[i];

        for (int i = 0; i < (1 << M); i++) {
            int lcm = 1, ct = N, num = 0;
            for (int j = 0; j < M; j++) {
                if ((i & (1 << j)) == 0) continue;
                num++;
                int m1 = arr[j] / gcd(arr[j], lcm);
                ct /= m1;
                lcm *= m1;
            }
            if (num % 2 == 1) ct *= -1;
            ans += ct;
        }
        cout << ans << endl;
    }

    return 0;
}