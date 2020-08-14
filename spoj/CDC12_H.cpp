
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 17)

pair<ll, ll> tree[2 * T];
int t, N, Q;

ll query(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    if (p < T) {
        tree[2 * p].second += tree[p].second;
        tree[2 * p + 1].second += tree[p].second;
    }
    tree[p].first += tree[p].second * (r - l + 1);
    tree[p].second = 0;

    if (a <= l && b >= r) return tree[p].first;

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
    tree[p].first += tree[p].second * (r - l + 1);
    tree[p].second = 0;

    if (a <= l && b >= r) {
        tree[p].second += val;
        return;
    }

    tree[p].first += (min(r, b) - max(l, a) + 1) * val;

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
        cout << "Scenario #" << t1 + 1 << ":\n";
        memset(tree, 0, sizeof tree);
        cin >> N >> Q;

        for (int i = 0; i < Q; i++) {
            string type;
            ll x, y;
            cin >> type >> x >> y;
            if (type == "modification") {
                update(x, y, 1);
                cout << "OK\n";
            } else {
                cout << query(x, y) << "\n";
            }
        }
    }

    return 0;
}
