#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, A, B, C;
int dp[4005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B >> C;
    for (int i = 1; i < 4005; i++) dp[i] = -1;

    vector<int> v{A, B, C};
    for (int i = 1; i < 4005; i++) {
        for (auto x : v) {
            if (i >= x && dp[i - x] != -1) {
                dp[i] = max(dp[i], 1 + dp[i - x]);
            }
        }
    }
    cout << dp[N] << endl;

    return 0;
}
