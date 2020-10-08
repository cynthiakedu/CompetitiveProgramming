#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll rSum[1005], cSum[1005], arr[1005][1005];
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            rSum[i] += arr[i][j];
            cSum[j] += arr[i][j];
        }
    }
    ll minRowSum = LLONG_MAX;
    int rIdx = -1;

    for (ll i = 0; i <= N; i++) {
        ll s = 0;
        for (ll j = 1; j <= N; j += 1) {
            ll j1 = 4 * j - 2;
            s += (4 * i - j1) * (4 * i - j1) * rSum[j];
        }
        if (s < minRowSum) {
            minRowSum = s;
            rIdx = i;
        }
    }

    ll minColSum = LLONG_MAX;
    int cIdx = -1;
    for (ll i = 0; i <= M; i++) {
        ll s = 0;
        for (ll j = 1; j <= M; j += 1) {
            ll j1 = 4 * j - 2;
            s += (4 * i - j1) * (4 * i - j1) * cSum[j];
        }
        if (s < minColSum) {
            minColSum = s;
            cIdx = i;
        }
    }
    cout << (minRowSum + minColSum) << endl;
    cout << rIdx << " " << cIdx << endl;

    return 0;
}
