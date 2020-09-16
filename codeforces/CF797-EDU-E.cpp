#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 100005
bool debug = false;

int N, Q, arr[MXN], dp[350][MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= sqrt(N); i++) {
        for (int j = N; j >= 1; j--) {
            int nxt = j + arr[j] + i;
            dp[i][j] = (nxt > N ? 1 : dp[i][nxt] + 1);
        }
    }
    cin >> Q;
    for (int q = 0, k, p; q < Q; q++) {
        cin >> p >> k;  //flipped the order
        if (k < sqrt(N)) {
            cout << dp[k][p] << "\n";
        } else {
            int ans = 0;
            while (p <= N) {
                ans++;
                p = arr[p] + p + k;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
