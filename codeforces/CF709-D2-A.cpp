#include <bits/stdc++.h>
using namespace std;
int N, B, D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> B >> D;
    int ct = 0;
    int ans = 0;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (x > B) continue;
        ct += x;
        if (ct > D) {
            ct = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
