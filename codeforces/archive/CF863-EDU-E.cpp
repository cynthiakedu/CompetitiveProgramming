#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
set<int> S;
vector<ii> v;
bool can[200005];
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1, l, r; i <= N; i++) {
        can[i] = true;
        cin >> l >> r;
        v.push_back({l - 1, -i});
        v.push_back({r, i});
        m[r]++;
    }
    sort(v.begin(), v.end());

    int idx = 0;
    while (idx < (int)v.size()) {
        int j = idx;
        if (S.size() == 1) {
            int x = *S.begin();
            can[x] = false;
        }
        while (j < (int)v.size() && v[j].first == v[idx].first) {
            if (v[j].second < 0) {
                S.insert(-v[j].second);
            } else {
                S.erase(v[j].second);
            }
            j++;
        }

        idx = j;
    }
    for (int i = 1; i <= N; i++) {
        if (can[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
