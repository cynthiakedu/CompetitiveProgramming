#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, K, arr[150005], cum[150005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        cum[i] = cum[i - 1] + arr[i];
    }
    int ans = INT_MAX, ans2 = -1;
    for (int i = 1; i <= N - K + 1; i++) {
        int d = cum[i + K - 1] - cum[i - 1];
        if (d < ans) {
            ans = d;
            ans2 = i;
        }
    }
    cout << ans2 << endl;

    return 0;
}
