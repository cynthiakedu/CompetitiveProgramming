#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll pos[11], neg[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (x >= 0)
            pos[x]++;
        else
            neg[-x]++;
    }
    ll ans = 0;
    for (int i = 1; i <= 10; i++) {
        ans += (ll)pos[i] * neg[i];
    }
    ans += pos[0] * (pos[0] - 1) / 2;
    cout << ans << endl;
    return 0;
}
