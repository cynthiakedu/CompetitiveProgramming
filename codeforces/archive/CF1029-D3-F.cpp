#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll arr[3];
vector<ll> v[3];
ll ans = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> arr[0] >> arr[1];
    arr[2] = arr[0] + arr[1];
    for (int i = 0; i < 2; i++) {
        vector<ll> v1, v2;
        for (int j = 1; j <= sqrt(arr[i]); j++) {
            if ((arr[i] % j) == 0) {
                v1.push_back(j);
                v2.push_back(arr[i] / j);
            }
        }
        reverse(v2.begin(), v2.end());
        v1.insert(v1.begin(), v2.begin(), v2.end());
        int idx = 0;
        for (int j = 1; j <= sqrt(arr[2]); j++) {
            if (arr[2] % j == 0) {
                idx = (int)(upper_bound(v1.begin() + idx, v1.end(), j) - v1.begin());
                if (idx > 0) {
                    if (arr[i] / v1[idx - 1] <= arr[2] / j) {
                        ans = min(ans, 2 * (j + arr[2] / j));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
