#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 18)
int N;

int tree[2 * T];

int query(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    if (a <= l && r <= b) return tree[p];

    int m = (l + r) / 2;
    if (b <= m) return query(a, b, l, m, 2 * p);
    if (a > m) return query(a, b, m + 1, r, 2 * p + 1);

    return query(a, b, l, m, 2 * p) + query(a, b, m + 1, r, 2 * p + 1);
}

void update(int k, int x) {
    tree[k + T] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

int main() {
    int ct = 0;
    while (cin >> N) {
        ct++;
        if (N == 0) return 0;
        if (ct > 1) cout << endl;
        cout << "Case " << ct << ":"
             << "\n";

        memset(tree, 0, sizeof tree);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &tree[T + i]);
        }
        for (int i = T - 1; i >= 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }

        string s;
        while (true) {
            cin >> s;
            if (s == "END") break;
            int x, y;
            scanf("%d %d", &x, &y);
            if (s == "S") {
                update(x, y);
            } else {
                printf("%d\n", query(x, y));
            }
        }
    }

    return 0;
}