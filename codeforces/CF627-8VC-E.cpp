#include <bits/stdc++.h>
using namespace std;

int R, C, N, K;
vector<int> blocks[3005];
map<int, int> m[3005];
long long ans1[3005], ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> N >> K;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        blocks[x].push_back(y);
    }
    for (int i = 1; i <= R; i++) {
        sort(blocks[i].begin(), blocks[i].end());
    }
    for (int i = 1; i <= R; i++) m[i][0]++, m[i][C + 1]++;

    int t, occ, t2;
    map<int, int>::iterator it, it2, it3, it4;
    vector<int> v(2 * K + 1);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= i; j++) {
            it3 = m[j].begin(), it4 = m[j].end();
            for (int x : blocks[i]) {
                m[j][x]++;
                it = it2 = m[j].upper_bound(x);

                for (t = 0; t <= K && it != it3; t += occ) {
                    occ = min((--it)->second, K + 1 - t);
                    for (int i = 0; i < occ; i++) v[t + i] = it->first;
                }
                reverse(v.begin(), v.begin() + t);

                for (int ct = K + 1; it2 != it4 && ct > 0; ct -= occ) {
                    occ = min((it++)->second, ct);
                    for (int i = 0; i < occ; i++, t++) v[t] = it->first;
                }
                int cd = t + t2 - K;
                for (int i = 1; i < cd && v[i - 1] < x; ++i)
                    ans1[j] += (v[i] - v[i - 1]) * (v[i + K] - v[i + K - 1]);
            }
            ans2 += ans1[j];
        }
    }
    cout << ans2 << "\n";

    return 0;
}