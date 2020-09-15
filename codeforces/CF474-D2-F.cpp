#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 100005
bool debug = false;
int n = 1 << 17;

int N, Q, tree[1 << 18];
vector<ii> v;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int queryGcd(int a, int b) {
    a += n;
    b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) {
            s = gcd(s, tree[a]);
            a++;
        }
        if (b % 2 == 0) {
            s = gcd(s, tree[b]);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1, s; i <= N; i++) {
        cin >> s;
        v.push_back({s, i});
        tree[n + i] = s;
    }

    for (int t = n; t >= 1; t--) {
        tree[t] = gcd(tree[2 * t], tree[2 * t + 1]);
    }

    sort(v.begin(), v.end());

    cin >> Q;
    for (int q = 0, l, r; q < Q; q++) {
        cin >> l >> r;
        int g = queryGcd(l, r);
        int pos1 = (int)(lower_bound(v.begin(), v.end(), ii{g, l}) - v.begin());
        int pos2 = (int)(upper_bound(v.begin(), v.end(), ii{g, r}) - v.begin());
        cout << r - l + 1 - (pos2 - pos1) << "\n";
    }

    return 0;
}
