#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e6;
int N;
ll arr[mxN + 5], mn[mxN + 5], mx[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        ll s = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            s += arr[i];
        }
        for (int i = 1; i <= N; i++) {
            mx[i] = arr[i];
            if (i > 1 && mx[i - 1] > 0) {
                mx[i] += mx[i - 1];
            }
        }
        for (int i = N; i >= 1; i--) {
            mn[i] = arr[i];
            if (i < N && mn[i + 1] < 0) {
                mn[i] += mn[i + 1];
            }
        }

        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            ll x = mn[i];
            if (i > 1) {
                x = min(x, s - mx[i - 1]);
            }
            x = min(x, s);
            if (x >= 0) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
