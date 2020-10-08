#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<pair<ii, int>> v1, v2;
set<ii> s1, s2;
int N, M;
int ans[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1, a, b; i <= N; i++) {
        cin >> a >> b;
        v1.push_back({{a, -b}, i});
    }
    cin >> M;
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        v2.push_back({{a, b}, i});
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i1 = 0, i2 = 0;
    while (i2 < (int)v2.size()) {
        while (i1 < (int)v1.size() && v1[i1].first.first <= v2[i2].first.first) {
            s1.insert({-v1[i1].first.second, v1[i1].second});
            i1++;
        }
        int j = i2;
        while (j < (int)v2.size() && v2[j].first.first == v2[i2].first.first) {
            ii p = v2[j].first;
            int id2 = v2[j].second;
            set<ii>::iterator it = s1.upper_bound({p.second, INT_MAX});
            if (it != s1.begin()) {
                it--;
                ans[(*it).second] = id2;
                s1.erase(it);
            }
            j++;
        }
        i2 = j;
    }
    if (s1.size() > 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
