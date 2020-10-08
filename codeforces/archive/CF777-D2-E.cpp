#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
map<int, int> heights, mina;
vector<int> v;
ll tree[1 << 18];
int n = (1 << 17);
ll findMax(int a, int b) {
    a += n, b += n;
    ll s = 0;
    while (a <= b) {
        if (a % 2 == 1) s = max(s, tree[a++]);
        if (b % 2 == 0) s = max(s, tree[b--]);
        a /= 2, b /= 2;
    }
    return s;
}

void add(int k, ll x) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1, a, b, h; i <= N; i++) {
        cin >> a >> b >> h;
        heights[b] += h;
        if (mina.count(b) == 0 || mina[b] > a) {
            mina[b] = a;
        }
    }

    for (auto p : heights) {
        v.push_back(p.first);
    }
    vector<ll> dp(v.size() + 5);

    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int b = v[i];
        int pos = (int)(upper_bound(v.begin(), v.begin() + i, mina[b]) - v.begin());
        ll tmp = findMax(pos, i) + heights[b];
        add(i, tmp);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
