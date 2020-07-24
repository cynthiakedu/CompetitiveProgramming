#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;
    ll ans = 0;
    for (int i = 0; i < K; i++) {
        int dx, dy;
        cin >> dx >> dy;
        if (dx == 0 && dy == 0) continue;
        int amtX, amtY;
        amtX = dx > 0 ? N - x : x - 1;
        amtY = dy > 0 ? M - y : y - 1;

        int xs = dx == 0 ? INT_MAX : amtX / abs(dx);
        int ys = dy == 0 ? INT_MAX : amtY / abs(dy);
        int s = min(xs, ys);
        ans += s;
        x += s * dx;
        y += s * dy;
    }
    cout << ans << endl;

    return 0;
}
