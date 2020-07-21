#include <bits/stdc++.h>
using namespace std;
int N, ans = 0, p = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            if (p > 0)
                p--;
            else
                ans++;
        } else {
            p += x;
        }
    }
    cout << ans << endl;

    return 0;
}
