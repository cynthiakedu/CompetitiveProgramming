#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, P, N;

vector<int> starts;
vector<ii> v;
int ans = INT_MAX;
int cum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        starts.clear();
        v.clear();
        cum = 0;
        ans = INT_MAX;

        cin >> N >> P;
        for (int i = 0, a, b; i < N; i++) {
            cin >> a >> b;
            starts.push_back(a);
            v.push_back({a, 1});
            v.push_back({b, -1});
        }
        sort(starts.begin(), starts.end());
        sort(v.begin(), v.end());

        int idx = 0;
        while (idx < v.size()) {
            int j = idx;
            if (cum >= P) {
                ans = 0;
            } else {
                int need = P - cum;
                int pos = (int)(lower_bound(starts.begin(), starts.end(), v[idx].first) - starts.begin());
                int idx2 = pos + need - 1;
                if (idx2 < N) {
                    ans = min(ans, starts[idx2] - v[idx].first);
                }
            }

            while (j < v.size() && v[j].first == v[idx].first) {
                cum += v[j].second;
                j++;
            }
            idx = j;
        }
        cout << "Case " << t + 1 << ": " << ans << "\n";
    }

    return 0;
}
// 1
// 5 3
// 1 3
// 8 12
// 6 9
// 14 17
// 2 7