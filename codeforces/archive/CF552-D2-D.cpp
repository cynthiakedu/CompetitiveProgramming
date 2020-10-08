#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[2005][2];
map<pair<ii, int>, set<int>> m;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

ll choose3(int n) {
    return (ll)n * (n - 2) * (n - 1) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int a = arr[j][1] - arr[i][1];
            int b = arr[i][0] - arr[j][0];
            int c = a * arr[i][0] + b * arr[i][1];
            int g1 = gcd(abs(a), abs(b));
            int g2 = gcd(g1, abs(c));
            a /= g2;
            b /= g2;
            c /= g2;
            if (c < 0) {
                c = -c;
                a = -a;
                b = -b;
            }
            m[{{a, b}, c}].insert(i);
            m[{{a, b}, c}].insert(j);
        }
    }

    ll ans = choose3(N);
    for (auto p : m) {
        ans -= choose3(p.second.size());
    }
    cout << ans << endl;
    return 0;
}
