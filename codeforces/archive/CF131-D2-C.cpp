#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, T;
ll binom[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int n = 1; n <= 60; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 || k == n) {
                binom[n][k] = 1;
                continue;
            }
            binom[n][k] = binom[n - 1][k - 1] + binom[n - 1][k];
        }
    }
    cin >> N >> M >> T;
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        int j = T - i;
        if (j < 1 || j > M) continue;
        if (i < 4 || i > N) continue;
        ans += binom[N][i] * binom[M][j];
    }
    cout << ans << endl;

    return 0;
}
