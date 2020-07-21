#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    s = 'a' + s;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        int b = s[i - 1] - 'a', c = s[i] - 'a';
        int d = max(b, c) - min(b, c);
        int d2 = 26 - d;
        ans += min(d, d2);
    }
    cout << ans << endl;

    return 0;
}
