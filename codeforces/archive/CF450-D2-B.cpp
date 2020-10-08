#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll x, y, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> n;
    vector<ll> v{x, y, y - x, -x, -y, x - y};
    cout << ((v[(n - 1) % 6] + 2 * MOD) % MOD) << endl;

    return 0;
}
