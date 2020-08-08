#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, M, arr[105][105];
ll dp[105][105], dp2[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> N) && (cin >> M)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j];
            }
        }
        for (int j = M - 1; j >= 0; j--) {
            for (int i = 0; i < N; i++) {
                if (j == M - 1) {
                    dp[i][j] = arr[i][j];
                    dp2[i][j] = -1;
                    continue;
                }
                dp[i][j] = INT_MAX;
                for (int k = -1; k <= 1; k++) {
                    int idx = (i + k + N) % N;
                    ll amt = arr[i][j] + dp[idx][j + 1];
                    if (amt < dp[i][j]) {
                        dp[i][j] = amt;
                        dp2[i][j] = (i + k + N) % N;
                    }
                    if (amt == dp[i][j] && idx < dp2[i][j]) {
                        dp2[i][j] = idx;
                    }
                }
            }
        }
        int idx;
        ll ans = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (dp[i][0] < ans) {
                ans = dp[i][0];
                idx = i;
            }
        }
        vector<ll> ans2 = {idx + 1};

        for (int i = 1; i < M; i++) {
            idx = dp2[idx][i - 1];
            ans2.push_back(idx + 1);
        }
        for (int i = 0; i < ans2.size(); i++) cout << ans2[i] << (i == ans2.size() - 1 ? "\n" : " ");
        cout << ans << endl;
    }

    return 0;
}
