#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> a >> b >> c >> d;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int m = i + c - b, n = i + a - d, t = c + a - b - d + i;
        if (1 <= m && m <= N && 1 <= n && n <= N) {
            if (1 <= t && t <= N) {
                ans++;
            }
        }
    }
    ans *= N;
    cout << ans << endl;
    return 0;
}
