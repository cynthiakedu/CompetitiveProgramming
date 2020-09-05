#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, int>
#define PI 3.14159265359

const int mxN = 1e5;
int N;
ll arr[mxN + 5];
int rev[mxN + 5];
vector<ii> v;
int n = (1 << 17);
ll tree[(1 << 18)];
ll ans;
ll getMax(int a, int b) {
    a += n, b += n;
    ll ret = 0;
    while (a <= b) {
        if (a % 2 == 1) ret = max(ret, tree[a++]);
        if (b % 2 == 0) ret = max(ret, tree[b--]);
        a /= 2;
        b /= 2;
    }
    return ret;
}

void change(int k, ll x) {
    k += n;
    tree[k] = max(tree[k], x);
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    v.push_back({0, 0});
    for (int i = 1, r, h; i <= N; i++) {
        cin >> r >> h;
        arr[i] = (ll)r * r * h;
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < (int)v.size(); i++) {
        rev[v[i].second] = i;
    }
    for (int i = 1; i <= N; i++) {
        int pos = (int)(lower_bound(v.begin(), v.end(), pair<ll, int>{arr[i], INT_MIN}) - v.begin());
        ll tmp = getMax(0, pos - 1) + arr[i];
        change(rev[i], tmp);
        ans = max(ans, tmp);
    }

    cout << setprecision(16) << ans * PI << endl;

    return 0;
}
