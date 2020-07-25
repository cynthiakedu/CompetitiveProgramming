#include <bits/stdc++.h>
using namespace std;
int N, arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int pos = (int)(upper_bound(arr, arr + N, 2 * arr[i]) - arr);
        ans = max(ans, pos - i);
    }
    cout << N - ans << endl;

    return 0;
}
