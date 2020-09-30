#include <bits/stdc++.h>
using namespace std;

int R, C, N, K;
vector<int> blocks[3005];
map<int, int> m[3005];
long long ans1[3005], ans2;
set<int> S;
int T[3005][3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> N >> K;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        blocks[x].push_back(y);
    }
    for (int i = 1; i <= R; i++) m[i][0]++, m[i][C + 1]++;

    vector<int> v(2 * K + 2);
    map<int, int>::iterator it, it2;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int x : blocks[i]) {
                m[j][x]++;
                int t = 0, occ;

                it = it2 = m[j].upper_bound(x);

                for (int ct = K + 1; ct > 0; ct -= occ) {
                    if (it == m[j].begin()) break;
                    --it;
                    auto p = (*it);
                    occ = min(p.second, ct);
                    for (int i = 0; i < occ; ++i, ++t) v[t] = p.first;
                }
                reverse(v.begin(), v.begin() + t);

                for (int ct = K + 1; it2 != m[j].end() && ct > 0; ct -= occ, ++it2) {
                    auto p = *it2;
                    occ = min(p.second, ct);
                    for (int i = 0; i < occ; ++i, ++t) v[t] = p.first;
                }

                for (int i = 1; i < t; ++i) {
                    if (i + K >= t || v[i - 1] >= x) break;
                    if (v[i + K] <= x) continue;
                    ans1[j] += (v[i] - v[i - 1]) * (v[i + K] - v[i + K - 1]);
                }
            }
            ans2 += ans1[j];
        }
    }
    cout << ans2 << "\n";

    return 0;
}