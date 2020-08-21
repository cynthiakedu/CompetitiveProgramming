#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K;
ll L, R;
double prob[1005];
double dp[1005][1005];

ll p(ll a, ll b) {
    if (b == 0) return 1;
    ll z = pow(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

ll count1(ll x) {
    if (x == 0) return 0;
    ll x1 = x;
    ll d = 0;
    while (x1 > 0) {
        x1 /= 10;
        d++;
    }
    ll right = x % (p(10, d - 1));
    ll left = (x - right) / p(10, d - 1);

    ll ret = 0;
    for (int i = 0; i < (left == 1 ? d - 1 : d); i++) {
        ret += p(10, i);
    }
    if (left == 1) ret += right + 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L >> R;
        ll ct = count1(R) - count1(L - 1);
        prob[i] = 1.0 * ct / (R - L + 1);
    }
    cin >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0) {
                dp[i][j] = (j == 0 ? 1.0 : 0.0);
                continue;
            }
            double& ret = dp[i][j];
            ret = (1 - prob[i]) * dp[i - 1][j];
            if (j >= 1) {
                ret += prob[i] * dp[i - 1][j - 1];
            }
        }
    }

    double ans = 0;
    int need = ceil(1.0 * N * K / 100);
    for (int i = need; i <= N; i++) {
        ans += dp[N][i];
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
