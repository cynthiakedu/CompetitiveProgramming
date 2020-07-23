#include <bits/stdc++.h>
using namespace std;
int N, L;
double arr[1005];
double ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i < N; i++) {
        ans = max(ans, (arr[i + 1] - arr[i]) / 2);
    }
    ans = max({ans, arr[1], L - arr[N]});
    cout << setprecision(16) << ans << endl;

    return 0;
}
