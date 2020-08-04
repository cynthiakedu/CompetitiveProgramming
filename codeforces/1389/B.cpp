#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
ll arr[100005], cumSum[100005], cumMax[100005], K, Z;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(cumSum, 0, sizeof cumSum);
        memset(cumMax, 0, sizeof cumMax);

        cin >> N >> K >> Z;
        for (int i = 0; i < N; i++) cin >> arr[i];
        for (int i = 0; i < N; i++) {
            cumSum[i] = arr[i];
            if (i > 0) cumSum[i] += cumSum[i - 1];
            if (i > 0) {
                cumMax[i] = arr[i] + arr[i - 1];
                cumMax[i] = max(cumMax[i], cumMax[i - 1]);
            }
        }

        ll ans = cumSum[K];
        for (int z = 0; z <= Z; z++) {
            if (K - 2 * z > 0) {
                ll ret = cumSum[K - 2 * z];
                ret += cumMax[K - 2 * z] * z;
                ans = max(ret, ans);
            }
            if (K - 2 * z + 1 > 0 && z > 0) {
                ll ret = cumSum[K - 2 * z + 1];
                ret += cumMax[K - 2 * z + 1] * (z - 1) + arr[K - 2 * z];
                ans = max(ret, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}