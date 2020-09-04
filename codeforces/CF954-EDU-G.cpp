#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 5e5;
int N, R;
ll K;
ll arr[mxN + 5], arr2[mxN + 5];

bool check(ll x) {
    ll v[mxN + 5] = {}, cum[mxN + 5] = {};
    for (int i = 1; i <= N; i++) {
        if (arr2[i] < x) {
            v[i] = x - arr2[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (v[i] != 0) {
            int l = max(0, i - (2 * R + 1));
            ll y = max(0LL, v[i] - (cum[i - 1] - cum[l]));
            cum[i] += y;
        }
        cum[i] += cum[i - 1];
        if (cum[i] > K) return false;
    }
    return cum[N] <= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mx = 0;
    cin >> N >> R >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        int r = min(i + R, N);
        int l = max(0, i - R - 1);
        arr2[i] = arr[r] - arr[l];
        mx = max(mx, arr2[i]);
    }

    ll l = 0, r = mx + K + 1;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << endl;

    return 0;
}
