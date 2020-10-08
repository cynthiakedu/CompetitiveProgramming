#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, arr[105];
ll dp[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    dp[N + 1] = 1;
    for (int i = N; i >= 1; i--) {
        int a = i;
        for (a; a < N + 1; a++) {
            if (arr[a] == 1) break;
        }
        if (a == N + 1) continue;
        int b = a + 1;
        for (b; b < N + 1; b++) {
            if (arr[b] == 1) break;
        }
        for (int j = a; j < b; j++) {
            dp[i] += dp[j + 1];
        }
    }
    cout << dp[1] << endl;

    return 0;
}
