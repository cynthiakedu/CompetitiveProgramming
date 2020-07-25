#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0;
string a, b;
int cum[2][200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= b.size(); i++) {
        cum[0][i] = cum[0][i - 1] + (b[i - 1] == '0');
        cum[1][i] = cum[1][i - 1] + (b[i - 1] == '1');
    }
    for (int i = 0; i < a.size(); i++) {
        int l = i + 1, r = b.size() - a.size() + i + 1;
        int c = 1 - (a[i] - '0');
        ans += cum[c][r] - cum[c][l - 1];
    }
    cout << ans << endl;

    return 0;
}
