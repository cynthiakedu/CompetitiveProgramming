#include <bits/stdc++.h>
using namespace std;
int N, D, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D;
    cin >> M;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        bool ok = true;
        if (y < -x + D) ok = false;
        if (y > -x + 2 * N - D) ok = false;
        if (y > x + D) ok = false;
        if (y < x - D) ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
