#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, arr[1005], L[1005], R[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        L[i] = 1;
        if (i > 1 && arr[i] >= arr[i - 1]) {
            L[i] = 1 + L[i - 1];
        }
    }
    for (int i = N; i >= 1; i--) {
        R[i] = 1;
        if (i < N && arr[i] >= arr[i + 1]) {
            R[i] = 1 + R[i + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, L[i] + R[i] - 1);
    }
    cout << ans << endl;
    return 0;
}
