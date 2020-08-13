#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 17)
pair<ll, ll> tree[2 * T];
int t, N, C;

ll query(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    if (p < T) {
        tree[2 * p].second += tree[p].second;
        tree[2 * p + 1].second += tree[p].second;
    }
    tree[p].first += (r - l + 1) * tree[p].second;
    tree[p].second = 0;

    if (a <= l && r <= b) return tree[p].first;

    int m = (l + r) / 2;
    if (b <= m) return query(a, b, l, m, 2 * p);
    if (a > m) return query(a, b, m + 1, r, 2 * p + 1);

    return query(a, b, l, m, 2 * p) + query(a, b, m + 1, r, 2 * p + 1);
}

void update(int a, int b, ll val, int l = 0, int r = T - 1, int p = 1) {
    if (p < T) {
        tree[2 * p].second += tree[p].second;
        tree[2 * p + 1].second += tree[p].second;
    }
    tree[p].first += (r - l + 1) * tree[p].second;
    tree[p].second = 0;
    if (a <= l && r <= b) {
        tree[p].second += val;
        return;
    }
    tree[p].first += val * (ll)(min(r, b) - max(l, a) + 1);
    int m = (l + r) / 2;
    if (b <= m) return update(a, b, val, l, m, 2 * p);
    if (a > m) return update(a, b, val, m + 1, r, 2 * p + 1);

    update(a, b, val, l, m, 2 * p);
    update(a, b, val, m + 1, r, 2 * p + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        cin >> N >> C;
        memset(tree, 0, sizeof tree);

        for (int i = 0; i < C; i++) {
            int type, p, q;
            ll v;
            cin >> type >> p >> q;
            if (type == 0) {
                cin >> v;
                update(p, q, v);
            } else {
                cout << query(p, q) << endl;
            }
        }
    }

    return 0;
}
