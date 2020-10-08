#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, M, ans;
set<ii> v[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) v[i].insert({-1, 0});

    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        set<ii>::iterator pos1 = v[a].lower_bound({c, INT_MIN});
        int len = (*(prev(pos1))).second + 1;
        ans = max(ans, len);

        set<ii>::iterator it = v[b].upper_bound({c, INT_MAX});
        ii p = *(prev(it));
        if (p.second >= len) continue;

        auto p2 = v[b].insert({c, len});
        it = p2.first;
        set<ii>::iterator it2 = next(it);

        while (it2 != v[b].end()) {
            p = *(it2);
            if (p.second <= len)
                v[b].erase(it2);
            else
                break;
            it2 = next(it);
        }
    }
    cout << ans << endl;

    return 0;
}
