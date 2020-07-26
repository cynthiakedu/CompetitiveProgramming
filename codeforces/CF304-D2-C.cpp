#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int N;
map<int, ll> x, y;
map<ii, ll> s;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
        s[ii(a, b)]++;
    }
    for (auto p : x) {
        ans += (p.second * (p.second - 1)) / 2;
    }
    for (auto p : y) {
        ans += (p.second * (p.second - 1)) / 2;
    }
    for (auto p : s) {
        if (p.second < 2) continue;
        ans -= (p.second * (p.second - 1) / 2);
    }
    cout << ans << endl;

    return 0;
}
