#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
double dp[1005];
int N, K, M;
double prob[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(dp, 0, sizeof dp);
        cin >> N >> K >> M;
        for (int i = 0; i < N; i++) cin >> prob[i];
        for (int j = M; j >= 1; j--) {
            if (j == M) {
                dp[j] = prob[0];
                continue;
            }
            for (int i = 0; i < N; i++) {
                dp[j] += prob[i] * pow(dp[j + 1], i);
            }
        }
        cout << "Case #" << t + 1 << ": " << setprecision(16) << pow(dp[1], K) << endl;
    }
    return 0;
}
