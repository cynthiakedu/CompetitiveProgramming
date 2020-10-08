#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
int N, D;
ii arr[100005];
ll cum[100005];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        cum[i] = cum[i - 1] + arr[i].second;
    }
    for (int i = 1; i <= N; i++) {
        int pos = (int)(lower_bound(arr + 1, arr + N + 1, ii{arr[i].first + D, LLONG_MIN}) - arr);
        ll amt = cum[pos - 1] - cum[i - 1];
        if (amt > ans) ans = amt;
    }
    cout << ans << endl;

    return 0;
}
