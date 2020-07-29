#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, D;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    ll ans = 0;
    for (int i = 0; i < N - 2; i++) {
        int pos = (int)(upper_bound(v.begin(), v.end(), v[i] + D) - v.begin());
        if (pos >= i + 3) {
            ans += (ll)(pos - 2 - i) * (pos - 2 - i + 1) / 2;
        }
    }
    cout << ans << endl;

    return 0;
}
