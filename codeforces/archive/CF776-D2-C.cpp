#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const ll mxS = 10e15 + 1;
ll N, K;
ll arr[100005];
map<ll, ll> m;
set<ll> poss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll x = 1;
    poss.insert(x);
    poss.insert(K);
    while (abs(K) != 1 && x < mxS) {
        x *= K;
        poss.insert(x);
    }
    ll ans = 0;
    m[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (auto y : poss) {
            if (m.count(arr[i] - y) > 0) {
                ans += m[arr[i] - y];
            }
        }
        m[arr[i]]++;
    }
    cout << ans << endl;

    return 0;
}
