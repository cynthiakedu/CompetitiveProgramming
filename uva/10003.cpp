#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int L, N, arr[1005];

int dp[1005][1005];

int solve(int l, int r, int a, int b) {
    if (b < a) return 0;
    int& ret = dp[l][r];
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int i = a; i <= b; i++) {
        ret = min(ret, r - l + solve(l, arr[i], a, i - 1) + solve(arr[i], r, i + 1, b));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        memset(dp, -1, sizeof dp);
        cin >> L;
        if (L == 0) return 0;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> arr[i];
        cout << "The minimum cutting is " << solve(0, L, 0, N - 1) << "." << endl;
    }

    return 0;
}
