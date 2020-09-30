#include <bits/stdc++.h>
using namespace std;

int R, C, N, K;
vector<int> blocks[3005];
long long ans1[3005], ans2;
set<int> S[3005];
int T[3005][3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> N >> K;
    for (int i = 0, x, y; i < N; ++i) {
        cin >> x >> y;
        blocks[x].push_back(y);
    }
    for (int i = 1; i <= R; ++i) {
        sort(blocks[i].begin(), blocks[i].end());
        S[i].insert(0), S[i].insert(C + 1);
        ++T[i][0], ++T[i][C + 1];
    }

    vector<int> v(2 * K + 2);
    set<int>::iterator it, it2, it3, it4;
    int t, occ, t2, p, ct, cd, ab = 0;

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= i; ++j) {
            it3 = S[j].begin(), it4 = S[j].end();
            for (int x : blocks[i]) {
                it = it2 = (S[j].insert(x)).first;
                T[j][x]++;

                for (t = 0; t < K && it != it3;) {
                    p = (*(--it));
                    occ = min(T[j][p], K - t);
                    for (int i = 0; i < occ; ++i, ++t) v[t] = p;
                }
                reverse(v.begin(), v.begin() + t);

                for (t2 = 0; it2 != it4 && t2 < K + 1; ++it2) {
                    p = *it2;
                    occ = min(T[j][p], K + 1 - t2);
                    for (int i = 0; i < occ; ++i, ++t2) v[t + t2] = p;
                }
                cd = min(t + t2 - K, t + 1);
                for (int i = 1; i < cd; ++i) {
                    ans1[j] += (v[i] - v[i - 1]) * (v[i + K] - v[i + K - 1]);
                }
            }
            ans2 += ans1[j];
        }
    }
    cout << ans2 << "\n";

    return 0;
}