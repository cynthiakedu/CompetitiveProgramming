#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
ll dim[2], R, k;
ll arr[2][mxN + 5], cum[2][mxN + 5];
ll total = 0;
double ans = 0;

bool can(ll num) {
    ll ret = 0;
    for (int i = 1; i <= dim[0]; i++) {
        ll x = arr[0][i];
        ll need = (num + x - 1) / x;
        int pos = (int)(lower_bound(arr[1] + 1, arr[1] + dim[1] + 1, need) - arr[1]);
        ret += dim[1] + 1 - pos;
    }
    return ret >= k;
}

vector<ll> getVals(ll num) {
    vector<ll> ret;
    for (int i = 1; i <= dim[0]; i++) {
        ll x = arr[0][i];
        ll need = num / x + 1;
        int pos = (int)(lower_bound(arr[1] + 1, arr[1] + dim[1] + 1, need) - arr[1]);
        for (int j = pos; j <= dim[1]; j++) {
            ret.push_back(x * arr[1][j]);
        }
    }
    sort(ret.begin(), ret.end());
    reverse(ret.begin(), ret.end());
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> dim[0] >> dim[1] >> R >> k;
    total = (dim[0] - R + 1) * (dim[1] - R + 1);
    for (int idx = 0; idx < 2; idx++) {
        for (int i = 1; i <= dim[idx]; i++) {
            ll l = max(1LL, i + 1 - R), r = min((ll)i, dim[idx] + 1 - R);
            arr[idx][i] = max(0LL, r - l + 1);
        }
        sort(arr[idx] + 1, arr[idx] + dim[idx] + 1);
    }

    ll l = 1, r = arr[0][dim[0]] * arr[1][dim[1]];
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (can(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    vector<ll> v = getVals(l);
    for (int i = 0; i < (int)v.size(); i++) {
        ll x = v[i];
        ans += (double)x / (1.0 * total);
    }
    for (int i = 0; i < (k - (int)v.size()); i++) {
        ll x = l;
        ans += (double)x / (1.0 * total);
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
