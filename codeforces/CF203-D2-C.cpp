#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll D;
ll A, B;
vector<ii> v;
vector<ll> cum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D;
    cin >> A >> B;
    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x * A + y * B, i});
    }
    sort(v.begin(), v.end());
    ll c = 0;
    cum.push_back(0);
    for (int i = 0; i < N; i++) {
        c += v[i].first;
        cum.push_back(c);
    }
    int pos = (int)(upper_bound(cum.begin(), cum.end(), D) - cum.begin());
    vector<int> ans;
    for (int i = 0; i < pos - 1; i++) {
        ans.push_back(v[i].second);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");

    return 0;
}