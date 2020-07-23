#include <bits/stdc++.h>
using namespace std;
int N, A, arr[105];
bool vis[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> A;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        int other = 2 * A - i;
        if (other < 1 || other > N) {
            ans += arr[i];
        } else {
            if (i == A) {
                ans += arr[i];
            } else if (arr[i] + arr[other] == 2) {
                ans += 2;
                vis[other] = true;
            }
        }
        vis[i] = true;
    }
    cout << ans << endl;

    return 0;
}
