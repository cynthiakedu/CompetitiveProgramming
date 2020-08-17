#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (8)
set<int> primes;
bool vis[1000005];
int t, N, Q;

int tree[2 * T];
int prime[2 * T];  // if this is 0, then isMixed = true

int query(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    // cout << "query" << endl;
    // cout << "query " << a << " " << b << " " << l << " " << r << " " << p << endl;
    if (b < l || a > r) return 0;  //no intersection

    if (a <= l && r <= b && prime[p]) {
        tree[p] = (r - l + 1) * (primes.count(prime[p]) ? 1 : 0);
        // cout << "visiting " << p << " " << tree[p] << endl;

        return tree[p];
    }

    int m = (l + r) / 2;

    if (prime[p]) {
        prime[2 * p] = prime[2 * p + 1] = prime[p];
    }
    int x = query(a, b, l, m, 2 * p);
    int y = query(a, b, m + 1, r, 2 * p + 1);

    if (!prime[2 * p] || !prime[2 * p + 1] || prime[2 * p] != prime[2 * p + 1]) {
        prime[p] = 0;
    }
    // cout << "tree[p] query " << p << " " << x + y << endl;
    tree[p] = tree[2 * p] + tree[2 * p + 1];
    return x + y;
}

void update(int a, int b, int v, int l = 0, int r = T - 1, int p = 1) {
    // cout << "update" << endl;
    // cout << "query " << a << " " << b << " " << l << " " << r << " " << p << endl;

    if (b < l || a > r) return;  //no intersection

    if (a <= l && r <= b) {
        prime[p] = v;
        tree[p] = (r - l + 1) * (primes.count(prime[p]) ? 1 : 0);
        return;
    }

    int m = (l + r) / 2;

    if (prime[p]) {
        prime[2 * p] = prime[2 * p + 1] = prime[p];
    }
    update(a, b, v, l, m, 2 * p);
    update(a, b, v, m + 1, r, 2 * p + 1);

    if (!prime[2 * p] || !prime[2 * p + 1] || prime[2 * p] != prime[2 * p + 1]) {
        prime[p] = 0;
    }
    tree[p] = tree[2 * p] + tree[2 * p + 1];
    // cout << "p after " << p << " " << tree[p] << " " << prime[p] << endl;
    // cout << "what about 6 "
    //      << " " << tree[6] << " " << prime[6] << endl;
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
            tree[i + T] = primes.count(x) > 0 ? 1 : 0;
            prime[i + T] = x;
        }
        for (int i = T - 1; i >= 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
            if (prime[2 * i] && prime[2 * i + 1] && prime[2 * i] == prime[2 * i + 1]) {
                prime[i] = prime[2 * i];
            }
        }
        // cout << "count 9 " << tree[9] << " " << tree[10] << " " << tree[11] << " " << tree[5] << " " << tree[2] << endl;

        for (int q = 0; q < Q; q++) {
            // cout << "q " << q << endl;
            int type, x, y, v;
            cin >> type >> x >> y;
            // cout << "type " << type << endl;
            if (type == 0) {
                cin >> v;
                update(x, y, v);
            } else {
                cout << query(x, y) << "\n\n";
            }
        }
        // cout << "done" << endl;
    }

    return 0;
}

// 1

// 5 2

// 78 2 13 12 3

// 1 1 2

// 0 4 4 5

// 1
// 5 4
// 2 4 3 5 6
// 1 1 3
// 1 2 4
// 0 2 4 3
// 1 1 3

// 1
// 5 2
// 2 4 4 4 6
// 0 3 5 3
// 1 2 4
