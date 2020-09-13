#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 4e5;
int N, arr[mxN + 5], ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int t = 25; t >= 0; t--) {
        int temp[mxN + 5] = {};
        for (int i = 1; i <= N; i++) {
            temp[i - 1] = arr[i] % (1 << t);
        }
        sort(temp, temp + N);

        ll tempCt = 0;
        for (int i = N; i >= 1; i--) {
            int r = arr[i] % (1 << t);
            int need = (1 << (t)) - r;
            ll pos = N - (ll)(lower_bound(temp, temp + N, need) - temp);
            tempCt += pos - (r >= need ? 1LL : 0LL);
        }
        tempCt /= 2LL;

        for (int i = N; i >= 1; i--) {
            int dig = (arr[i] >> t) & (1);
            if ((N - 1) % 2 == 1 && dig == 1) {
                tempCt++;
            }
        }
        if (tempCt % 2 == 1) ans += (1 << t);
    }
    cout << ans << endl;

    return 0;
}
