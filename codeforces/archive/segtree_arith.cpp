#include <bits/stdc++.h>
using namespace std;

const int T = 1 << 12;
int tree[2][2 * T][3];
int val[2], idx;

void propogate(int l, int r, int x) {
    tree[idx][x][0] += (r - l + 1) * tree[idx][x][2];
    tree[idx][x][0] += (r - l) * (r - l + 1) / 2 * tree[idx][x][1];

    if (x < T) {
        tree[idx][2 * x][1] += tree[idx][x][1];
        tree[idx][2 * x][2] += tree[idx][x][2];

        tree[idx][2 * x + 1][1] += tree[idx][x][1];
        tree[idx][2 * x + 1][2] += tree[idx][x][2] + tree[idx][x][1] * ((r - l + 1) / 2);
    }
    tree[idx][x][1] = 0, tree[idx][x][2] = 0;
}

void update(int a, int b, int l = 0, int r = T - 1, int x = 1) {
    propogate(l, r, x);

    if (a <= l && b >= r) {
        tree[idx][x][1] += val[0];
        tree[idx][x][2] += val[1] + val[0] * (l - a);
        return;
    }

    int l2 = a <= l ? l - a : 0;
    int r2 = l2 + (max(a, l) - min(b, r));
    tree[idx][x][0] += (r2 - l2 + 1) * val[1];
    tree[idx][x][0] += (l2 + r2) * (r2 - l2 + 1) / 2 * val[0];

    int m = (l + r) / 2;
    if (b <= m) return update(a, b, l, m, 2 * x);
    if (a > m) return update(a, b, m + 1, r, 2 * x + 1);

    update(a, b, l, m, 2 * x), update(a, b, m + 1, r, 2 * x + 1);
}

int query(int a, int b, int l = 0, int r = T - 1, int x = 1) {
    // cout << "query " << a << " " << b << " " << l << " " << r << " " << x << endl;
    propogate(l, r, x);

    if (a <= l && b >= r) return tree[idx][x][0];

    int m = (l + r) / 2;
    if (b <= m) return query(a, b, l, m, 2 * x);
    if (a > m) return query(a, b, m + 1, r, 2 * x + 1);

    return query(a, b, l, m, 2 * x) + query(a, b, m + 1, r, 2 * x + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // cout << query(1, 3) << "\n";
    // val[0] = 1, val[1] = 2, update(0, 2);
    // val[0] = 2, val[1] = 1, update(1, 4);
    // val[0] = 0, val[1] = 3, update(3, 3);
    // val[0] = 4, val[1] = 3, update(2, 4);
    // cout << "[0, 2] " << query(0, 2) << "\n";
    // cout << "[1, 4] " << query(1, 4) << "\n";
    // cout << "[3, 3] " << query(3, 3) << "\n";
    for (int i = 0; i < 300; i++) {
        val[0] = 1, val[1] = 2;
        update(3, 200);
    }

    return 0;
}
