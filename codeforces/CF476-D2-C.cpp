#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    ll ans = ((((b * (b - 1) / 2) % MOD) * a) % MOD * (a + 2)) % MOD;

    cout << ans << endl;
    return 0;
}
