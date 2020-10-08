#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, S, K;
char colors[55];
vector<array<int, 2>> arr;  //amount, id
int dp[55][2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S >> K;
    arr.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> colors[i];
    }
    memset(dp, -1, sizeof dp);
    sort(arr.begin() + 1, arr.begin() + N + 1);

    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= K; j++) {
            if (arr[i][0] >= j) {
                dp[i][j] = 0;
                continue;
            }
            for (int k = i + 1; k <= N; k++) {
                if (colors[arr[k][1]] == colors[arr[i][1]]) continue;
                if (arr[k][0] == arr[i][0]) continue;
                if (dp[k][j - arr[i][0]] != -1) {
                    int amt = dp[k][j - arr[i][0]] + abs(arr[i][1] - arr[k][1]);
                    if (dp[i][j] == -1 || amt < dp[i][j]) {
                        dp[i][j] = amt;
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= N; i++) {
        if (dp[i][K] != -1) {
            int amt = dp[i][K] + abs(arr[i][1] - S);
            if (ans == -1 || amt < ans) {
                ans = amt;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
