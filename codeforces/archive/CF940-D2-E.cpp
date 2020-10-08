#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
ll N, arr[mxN + 5], c;
ll memo[20][mxN + 5];

ll dp[mxN + 5], s;

ll getMin(int l, int r) {
    int k = log2(r - l + 1);
    return min(memo[k][l], memo[k][r - (1 << k) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> c;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s += arr[i];
    }

    for (int i = 0; i <= log2(N); i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 0) {
                memo[i][j] = arr[j];
                continue;
            }
            int r = j + (1 << i) - 1;
            if (r > N) continue;
            memo[i][j] = min(memo[i - 1][j], memo[i - 1][r - (1 << (i - 1)) + 1]);
        }
    }

    for (int i = N; i >= 1; i--) {
        if (N - i + 1 < c) {
            dp[i] = 0;
        } else {
            dp[i] = max(dp[i + 1], dp[i + c] + getMin(i, i + c - 1));
        }
    }
    cout << s - dp[1] << endl;
    return 0;
}
