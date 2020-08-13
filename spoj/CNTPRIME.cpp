#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 17)
set<int> primes;
bool vis[1000005];
int t, N, Q;

ii tree[2 * T];

int query(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    if (p < T) {
        tree[2 * p].second = tree[p].second;
        tree[2 * p + 1].second = tree[p].second;
    }
    if (tree[p].second > 0) {
        tree[p].first = (primes.count(tree[p].second) ? 1 : 0) * (r - l + 1);
        tree[p].second = 0;
    }

    if (a <= l && r <= b) {
        return tree[p].first;
    }

    int m = (l + r) / 2;
    if (b <= m) return query(a, b, l, m, 2 * p);
    if (a > m) return query(a, b, m + 1, r, 2 * p + 1);

    return query(a, b, l, m, 2 * p) + query(a, b, m + 1, r, 2 * p + 1);
}

void prop(int l, int r, int p) {
    if (p < T) {
        tree[2 * p].second = tree[p].second;
        tree[2 * p + 1].second = tree[p].second;
    }
    if (tree[p].second > 0) {
        tree[p].first = (primes.count(tree[p].second) ? 1 : 0) * (r - l + 1);
        tree[p].second = 0;
    }
}

void update(int a, int b, int v, int l = 0, int r = T - 1, int p = 1) {
    prop(l, r, p);

    if (a <= l && r <= b) {
        tree[p].second = v;
        return;
    }

    int m = (l + r) / 2;
    if (b <= m) {
        update(a, b, v, l, m, 2 * p);
    } else if (a > m) {
        update(a, b, v, m + 1, r, 2 * p + 1);
    } else {
        update(a, b, v, l, m, 2 * p);
        update(a, b, v, m + 1, r, 2 * p + 1);
    }
    if (p < T) {
        prop(l, m, 2 * p);
        prop(m + 1, r, 2 * p + 1);
        tree[p].first = tree[2 * p].first + tree[2 * p + 1].first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < 1000005; i++) {
        if (vis[i]) continue;
        primes.insert(i);
        for (int j = i; j < 1000005; j += i) {
            vis[j] = true;
        }
    }

    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        cout << "Case " << t1 + 1 << ":\n\n";
        cin >> N >> Q;
        memset(tree, 0, sizeof tree);
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            tree[i + T].first = primes.count(x) > 0;
        }
        for (int i = T - 1; i >= 0; i--) {
            tree[i].first = tree[2 * i].first + tree[2 * i + 1].first;
        }

        for (int q = 0; q < Q; q++) {
            int type, x, y, v;
            cin >> type >> x >> y;
            if (type == 0) {
                cin >> v;
                update(x, y, v);
            } else {
                cout << query(x, y) << "\n\n";
            }
        }
    }

    return 0;
}

// 1

// 5 2

// 78 2 13 12 3

// 1 1 2

// 0 4 4 5
