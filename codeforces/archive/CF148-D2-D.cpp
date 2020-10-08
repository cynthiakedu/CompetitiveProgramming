#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

double dp[1005][1005];
int W, B;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> B;
    for (int w = 0; w < 1005; w++) {
        for (int b = 0; b < 1005; b++) {
            if (w == 0) {
                dp[w][b] = 0.0;
                continue;
            } else if (b == 0) {
                dp[w][b] = 1.0;
                continue;
            }
            double& ret = dp[w][b];
            ret = 1.0 * w / (w + b);
            if (b == 1) continue;

            double x = 0, y = 0;
            if (b >= 3) {
                x = (1.0 * (b - 2) / (w + b - 2)) * dp[w][b - 3];
            }
            y = (1.0 * w / (w + b - 2)) * dp[w - 1][b - 2];
            ret += (1.0 * b / (w + b)) * (1.0 * (b - 1) / (w + b - 1)) * (x + y);
        }
    }
    cout << setprecision(16) << dp[W][B] << endl;
    return 0;
}
