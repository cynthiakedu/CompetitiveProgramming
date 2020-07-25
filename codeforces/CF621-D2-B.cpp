#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
map<int, ll> m1;
map<int, ll> m2;

ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        m1[x + y]++;
        m2[x - y]++;
    }
    for (auto p : m1) {
        ll t = (p.second * (p.second - 1)) / 2;
        ans += t;
    }
    for (auto p : m2) {
        ll t = (p.second * (p.second - 1)) / 2;
        ans += t;
    }
    cout << ans << endl;

    return 0;
}
