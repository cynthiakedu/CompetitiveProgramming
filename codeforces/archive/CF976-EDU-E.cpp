#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
bool debug = false;
const int mxN = 2e5;
ll N, a, b, arr[mxN + 5][2], goodDiff, ans;
ii diff[mxN + 5];
bool isTopB[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> a >> b;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        goodDiff += arr[i][1];
        diff[i] = {arr[i][0] - arr[i][1], i};
    }
    if (b == 0) {
        cout << goodDiff << endl;
        return 0;
    }
    b = min(b, N);
    sort(diff + 1, diff + N + 1);
    reverse(diff + 1, diff + N + 1);
    for (int i = 1; i <= N; i++) {
        if (debug) cout << "sorted " << arr[diff[i].second][0] << " " << arr[diff[i].second][1] << endl;
        if (i <= b) {
            goodDiff += max(0LL, diff[i].first);
            isTopB[diff[i].second] = true;
        }
    }
    if (debug) cout << "good diff " << goodDiff << endl;
    for (int i = 1; i <= N; i++) {
        ll betterDiff = max(0LL, (1LL << a) * arr[i][0] - arr[i][1]);
        ll oriDiff = max(0LL, arr[i][0] - arr[i][1]);
        if (isTopB[i]) {
            ll tmp = goodDiff + betterDiff - oriDiff;
            if (debug) cout << "final " << i << " " << tmp << endl;
            ans = max(ans, tmp);
        } else {
            ans = max(ans, goodDiff + betterDiff - max(0LL, diff[b].first));
        }
    }
    cout << ans << endl;

    return 0;
}
