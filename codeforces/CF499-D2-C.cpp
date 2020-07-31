#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll a, b, c, d;
ll N, A, B, C;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C;
        ll x = a * A + b * B + C;
        ll y = c * A + d * B + C;
        if ((x > 0 && y < 0) || (x < 0 && y > 0)) ans++;
    }
    cout << ans << endl;

    return 0;
}
