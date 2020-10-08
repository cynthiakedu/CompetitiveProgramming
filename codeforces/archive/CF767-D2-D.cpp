#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, M, K;
ll lst = -1;
vector<ii> v;
ll amt, A;
vector<ll> b, ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        v.push_back({x, 1});
    }
    for (int i = 1, x; i <= M; i++) {
        cin >> x;
        v.push_back({x, -i});
    }
    v.push_back({-1, 0});
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int idx = 0;
    while (idx < v.size()) {
        ll temp = ((lst != -1) ? (lst - v[idx].first) * K : 0);
        ll mn = min(temp, A);
        A -= mn;
        temp -= mn;
        mn = min(temp, (ll)b.size());
        for (int i = 0; i < mn; i++) {
            ll x = b.back();
            b.pop_back();
            ans2.push_back(x);
        }

        int j = idx;
        while (j < v.size() && v[j].first == v[idx].first) {
            ii p = v[j];
            if (p.second == 1) A++;
            if (p.second <= -1) b.push_back(-p.second);
            j++;
        }
        lst = v[idx].first;
        idx = j;
    }
    if (A > 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans2.size() << endl;
    for (int i = 0; i < ans2.size(); i++) cout << ans2[i] << (i == ans2.size() - 1 ? "\n" : " ");

    return 0;
}
