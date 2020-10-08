#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, arr[200005];

map<int, ll> once, twice, three;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        ll a2 = 0, a3 = 0;
        if (x % K == 0) {
            a2 = once[x / K];
            a3 = twice[x / K];
        }
        once[x]++;
        twice[x] += a2;
        three[x] += a3;
    }
    ll ans = 0;
    for (auto p : three) {
        ans += p.second;
    }
    cout << ans << endl;
    return 0;
}
