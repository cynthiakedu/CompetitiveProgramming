#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 17)
int N, K;
int tree[2 * T];

int getSign(int x) {
    return (x > 0 ? 1 : x < 0 ? -1 : 0);
}

int getProd(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    if (a > r || b < l) return 1;
    if (a <= l && b >= r) return tree[p];
    int m = (l + r) / 2;
    return getProd(a, b, l, m, 2 * p) * getProd(a, b, m + 1, r, 2 * p + 1);
}

void update(int k, int x) {
    k += T;
    tree[k] = x > 0 ? 1 : x < 0 ? -1 : 0;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] * tree[2 * k + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> N) && (cin >> K)) {
        memset(tree, 1, sizeof tree);
        for (int i = 1; i <= N; i++) {
            cin >> tree[T + i];
            tree[T + i] = getSign(tree[T + i]);
        }
        for (int i = T - 1; i >= 0; i--) {
            tree[i] = tree[2 * i] * tree[2 * i + 1];
        }
        for (int i = 0; i < K; i++) {
            char type;
            int x, y;
            cin >> type >> x >> y;
            if (type == 'C') {
                update(x, y);
            } else {
                int ans = getProd(x, y);
                cout << (ans > 0 ? '+' : ans < 0 ? '-' : '0');
            }
        }
        cout << endl;
    }

    return 0;
}