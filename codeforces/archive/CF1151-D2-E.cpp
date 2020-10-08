#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
ll N, arr[mxN + 5];
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ans += arr[i] * (N - arr[i] + 1);
    }

    for (int i = 1; i < N; i++) {
        ll x = arr[i], y = arr[i + 1];
        ll a = min(x, y), b = max(x, y);
        ans -= a * (N - b + 1);
    }
    cout << ans << endl;

    return 0;
}
