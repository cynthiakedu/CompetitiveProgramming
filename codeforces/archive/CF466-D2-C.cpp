#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, s, arr[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s += arr[i];
        arr[i] += arr[i - 1];
    }
    if (s % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v1, v2;
    for (int i = 2; i <= N - 1; i++) {
        if (arr[i - 1] == s / 3) {
            v1.push_back(i);
        }
        if (arr[i] == 2 * (s / 3)) {
            v2.push_back(i);
        }
    }
    ll ans = 0;
    for (auto x : v1) {
        ll pos = (ll)(lower_bound(v2.begin(), v2.end(), x) - v2.begin());
        ans += v2.size() - pos;
    }
    cout << ans << endl;

    return 0;
}
