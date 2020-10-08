#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, a, b, c, d, arr[2005][2];

ll dist(ll p1, ll p2, ll q1, ll q2) {
    return (p1 - q1) * (p1 - q1) + (p2 - q2) * (p2 - q2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> a >> b >> c >> d;
    ll a1 = 0, a2 = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        a1 = max(a1, dist(a, b, arr[i][0], arr[i][1]));
        a2 = max(a2, dist(c, d, arr[i][0], arr[i][1]));
    }
    ll ans = min(a1, a2);
    for (int i = 0; i < N; i++) {
        ll d1 = dist(a, b, arr[i][0], arr[i][1]);
        ll other = 0;
        for (int j = 0; j < N; j++) {
            ll d2 = dist(a, b, arr[j][0], arr[j][1]);
            if (d2 > d1) {
                other = max(other, dist(c, d, arr[j][0], arr[j][1]));
            }
        }
        ans = min(ans, d1 + other);
    }
    cout << ans << endl;

    return 0;
}
