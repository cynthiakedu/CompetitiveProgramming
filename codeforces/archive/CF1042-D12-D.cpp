#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
ll arr[15][100005];
ll arr2[15][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr2[i][arr[i][j]] = j;
        }
    }

    ll ans = 0;
    int idx = 1;
    while (idx <= N) {
        ll mn = N - idx + 1;
        for (int i = 2; i <= M; i++) {
            int j = idx;
            ll s2 = arr2[i][arr[1][idx]];
            ll k = s2;
            while (j <= N && k <= N && k <= s2 + mn && arr[1][j] == arr[i][k]) {
                j++;
                k++;
            }
            mn = min(mn, k - s2);
        }
        ans += (ll)mn * (mn + 1) / 2;

        idx += mn;
    }
    cout << ans << endl;

    return 0;
}
