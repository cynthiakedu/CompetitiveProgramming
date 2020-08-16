#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int a[100005], b[100005];
int N, M;
int ct = 0;
int ans[100005][2];
int mnW = INT_MAX, mnIdx = -1;
vector<ii> v;
vector<ii> v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
        if (b[i] == 1) {
            v.push_back({a[i], i});
        } else {
            v2.push_back({a[i], i});
        }
    }

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v.size(); i++) {
        ans[v[i].second][0] = i + 1;
        ans[v[i].second][1] = i + 2;
    }

    int l = 0, r = 2;
    for (auto p : v2) {
        if (r > v.size()) {
            cout << -1 << endl;
            return 0;
        }

        if (v[r - 1].first > p.first) {
            cout << -1 << endl;
            return 0;
        }
        ans[p.second][0] = l + 1;
        ans[p.second][1] = r + 1;
        l++;
        if (l == r - 1) {
            l = 0;
            r++;
        }
    }
    for (int i = 1; i <= M; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}
