#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int a, b, c, d, e, f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    int ans = (a + b + c) * (a + b + c) - a * a - c * c - e * e;
    cout << ans << endl;

    return 0;
}
