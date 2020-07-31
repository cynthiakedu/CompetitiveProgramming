#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[200005];
int mn = INT_MAX, l = -1, r;
int mx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (l == -1 && arr[i] == mn) l = i;
        if (arr[i] == mn) r = i;
    }
    mx = (l - 1) + (N - r);

    int ct = 0;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] != mn) ct++;
        if (arr[i] == mn) {
            mx = max(mx, ct);
            ct = 0;
        }
    }

    ll ans = (ll)mn * N + mx;
    cout << ans << endl;

    return 0;
}
