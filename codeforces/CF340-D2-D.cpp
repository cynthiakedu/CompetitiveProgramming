#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[100005], b[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        b[i] = N + 5;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int x = arr[i];
        int pos = (int)(lower_bound(b + 1, b + N + 1, x) - b);
        ans = max(ans, pos);
        b[pos] = x;
    }
    cout << ans << endl;

    return 0;
}
