#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
ll N, Q, arr[mxN + 5];
vector<int> tree[(1 << 19)];
ll n = 1LL << 18;
ll total;

ll getOneAmt(int idx, ll x, bool isLeft) {
    vector<int> v = tree[idx];
    if (isLeft) return (ll)(upper_bound(v.begin(), v.end(), x) - v.begin());
    return (ll)(v.size() - (ll)(lower_bound(v.begin(), v.end(), x) - v.begin()));
}
ll getAmt(int a, int b, ll x, bool isLeft) {
    a += n;
    b += n;
    ll s = 0;
    while (a <= b) {
        if (a % 2 == 1) {
            s += getOneAmt(a, x, isLeft);
            a++;
        }
        if (b % 2 == 0) {
            s += getOneAmt(b, x, isLeft);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return s;
}
ll dp[mxN + 5];

ll binom(ll x) {
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    total = binom(N);
    for (ll i = 1; i <= N; i++) dp[i] = i * (i - 1) / 2;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cout << "here " << endl;
    for (int i = 1; i <= N; i++) {
        tree[i + n].push_back(arr[i]);
    }
    cout << "here 2" << endl;
    for (int i = n - 1; i >= 1; i--) {
        merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(), tree[i].begin());
    }

    // for (int i = 0, d, u, l, r; i < Q; i++) {
    //     cin >> l >> d >> r >> u;
    //     ll ans = 0;
    //     ans += binom(l - 1) + binom(d - 1) + binom(N - u) + binom(N - r);
    //     ll a = getAmt(1, l - 1, d - 1, true);
    //     ll b = getAmt(1, l - 1, u + 1, false);
    //     ll c = getAmt(r + 1, N, d - 1, true);
    //     ll z = getAmt(r + 1, N, u + 1, false);

    //     ans -= binom(a) + binom(b) + binom(c) + binom(z);
    //     ans = binom(N) - ans;
    //     cout << ans << "\n";
    // }
    return 0;
}
