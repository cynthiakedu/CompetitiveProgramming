#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, X;
ii arr[200005];
int cost[200005];
map<int, vector<pair<ii, int>>> m;
map<int, vector<int>> cumMn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        arr[i] = ii(l, r), cost[i] = c;
        m[r - l + 1].push_back(pair<ii, int>{ii(l, r), c});
    }
    for (auto p : m) {
        sort(m[p.first].begin(), m[p.first].end());
        vector<int> v(m[p.first].size());
        int mn = INT_MAX;
        for (int i = m[p.first].size() - 1; i >= 0; i--) {
            mn = min(mn, m[p.first][i].second);
            v[i] = mn;
        }
        cumMn[p.first] = v;
    }
    bool ok = false;
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int l = arr[i].first, r = arr[i].second;
        int need = X - (r - l + 1);
        if (need <= 0) continue;
        int pos = (int)(lower_bound(m[need].begin(), m[need].end(), pair<ii, int>{ii(r + 1, r + 1), INT_MIN}) - m[need].begin());
        if (pos < m[need].size()) {
            ok = true;
            ans = min(ans, cost[i] + cumMn[need][pos]);
        }
    }
    if (ok) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
