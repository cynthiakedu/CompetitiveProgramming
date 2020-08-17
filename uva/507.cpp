#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll arr[20005];
ll dp[20005];
ll dp2[20005];
int s;
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(dp, 0, sizeof dp);
        memset(dp2, 0, sizeof dp2);
        ll mx = LLONG_MIN;
        int mxl = 0;
        int mxIdx = -1;
        cin >> s;
        for (int i = 1; i < s; i++) {
            cin >> arr[i];
        }
        dp[1] = arr[1];
        dp2[1] = 1;
        for (int i = 2; i < s; i++) {
            if (dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + arr[i];
                dp2[i] = dp2[i - 1];
            } else {
                // cout << "i " << arr[i] << endl;
                dp[i] = arr[i];
                dp2[i] = i;
            }
        }
        for (int i = 1; i < s; i++) {
            if (dp[i] > mx) {
                mx = dp[i];
                mxIdx = i;
                mxl = i - dp2[i];
            } else if (dp[i] == mx) {
                if (i - dp2[i] > mxl) {
                    mxl = i - dp2[i];
                    mxIdx = i;
                }
            }
        }
        if (mx <= 0) {
            cout << "Route " << t << " has no nice parts" << endl;
        } else {
            cout << "The nicest part of route " << t << " is between stops " << dp2[mxIdx] << " and " << mxIdx + 1 << endl;
        }
    }

    return 0;
}
