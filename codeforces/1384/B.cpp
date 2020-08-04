#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int T, N, K, L, arr[300005];

bool solve() {
    cin >> N >> K >> L;
    bool ok = true;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] > L) ok = false;
        arr[i] = L - arr[i];
        // cout << "arr1 " << i << " " << arr[i] << endl;
    }
    if (!ok) {
        return false;
    }
    int a = INT_MAX, b = INT_MAX;
    bool A = true, B = true;
    for (int i = N; i >= 1; i--) {
        if (arr[i] >= K) {
            a = K, b = 0;
            continue;
        }
        // cout << "arr " << arr[i] << endl;
        a = min(a - 1, arr[i]);
        b = min(b + 1, arr[i]);
        // cout << "i " << i << " " << a << " " << b << endl;
        if (a < 0) A = false;
        if (b < 0) B = false;

        if (!A && !B) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        bool ok = solve();
        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}