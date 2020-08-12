#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int N, M;
int arr[100005];
vector<pair<ll, ll>> v;
ll S = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, -i});
        v.push_back({y, i});
    }
    sort(v.begin(), v.end());
    ll mx = 0;
    int idx = 0;
    ll ans = 0;
    while (idx < v.size()) {
        ll S1 = 0;

        mx = max(mx, v[idx].first);

        int j = idx;
        while (j < v.size() && v[j].first == v[idx].first) {
            ll a = v[j].first, b = v[j].second;
            if (b < 0) {
                arr[-b] = (S - (a == 0 ? 1 : 0) + MOD) % MOD;
            } else {
                S1 = (S1 + (S - arr[b]) + 2 * MOD) % MOD;
            }
            j++;
        }
        ans = S1;
        idx = j;
        S = (S + S1) % MOD;
    }
    cout << (mx == N ? ans : 0) << endl;

    return 0;
}
