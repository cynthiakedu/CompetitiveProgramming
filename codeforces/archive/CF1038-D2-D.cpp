#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll arr[500005];
ll S = 0;
ll ans = LLONG_MIN;
ll mn[500005], mn2[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        S += abs(arr[i]);
    }

    for (int i = 1; i <= N; i++) {
        mn[i] = arr[i];
        if (i > 1) {
            mn[i] = min(mn[i], mn[i - 1]);
        }
    }
    for (int i = N; i >= 1; i--) {
        mn2[i] = arr[i];
        if (i < N) {
            mn2[i] = min(mn2[i], mn2[i + 1]);
        }
    }

    for (int i = 1; i <= N; i++) {
        ll S1 = S;
        if (arr[i] < 0) S1 += 2 * arr[i];

        if (i > 1) {
            ll a = mn[i - 1];
            if (a > 0) {
                S1 -= 2 * a;
            }
        }
        if (i < N) {
            ll b = mn2[i + 1];
            if (b > 0) {
                S1 -= 2 * b;
            }
        }
        ans = max(ans, S1);
    }
    cout << ans << endl;

    return 0;
}
