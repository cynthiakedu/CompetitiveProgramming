#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
ll arr[200005], cum[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(arr, 0, sizeof arr);
        memset(cum, 0, sizeof cum);

        cin >> N;
        ll evenSum = 0;
        for (int i = 1; i <= N; i++) cin >> arr[i];
        for (int i = 1; i <= N; i++) {
            cum[i] = i % 2 == 0 ? arr[i] : -arr[i];
            cum[i] += cum[i - 1];
            // cout << "cum " << i << " " << cum[i] << endl;
            if (i % 2 == 1) evenSum += arr[i];
        }
        bool okE = false, okO = false;
        ll mxE = LLONG_MIN, mxO = LLONG_MIN;
        ll ans = evenSum;
        for (int i = N; i >= 1; i--) {
            if (i % 2 == 1) {
                mxO = max(mxO, cum[i]);
                okO = true;
                if (okE) {
                    ans = max(ans, evenSum + mxE - cum[i - 1]);
                }
            } else {
                mxE = max(mxE, cum[i]);
                okE = true;
                if (okO) {
                    ans = max(ans, evenSum + mxO - cum[i - 1]);
                }
            }

            // cout << "try " << i << " " << evenSum + (i % 2 ? mxE : mxO) - cum[i - 1] << endl;
        }
        cout << ans << endl;
    }

    return 0;
}