#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int M, N, K, arr[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;
    for (int i = 0; i < M; i++) {
        vector<bool> dp(105, false);

        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            arr[i] = abs(arr[i]) % K;
        }

        dp[0] = true;

        for (int i = 0; i < N; i++) {
            vector<bool> ne(105, false);
            for (int j = 0; j < K; j++) {
                ne[j] = dp[(j - arr[i] + K) % K] || dp[(j + arr[i]) % K];
            }
            dp = ne;
        }
        cout << (dp[0] ? "Divisible" : "Not divisible") << endl;
    }

    return 0;
}
