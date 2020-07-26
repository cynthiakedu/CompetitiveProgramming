#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ll N, R, AVG;
vector<ii> v;
ll s = 0;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> R >> AVG;
    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;
        s += x;
        v.push_back(ii{y, R - x});
    }
    ll need = AVG * N - s;
    if (need <= 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        ll amt = min(v[i].second, need);
        need -= amt;
        ans += amt * v[i].first;
        if (need == 0) break;
    }
    cout << ans << endl;

    return 0;
}
