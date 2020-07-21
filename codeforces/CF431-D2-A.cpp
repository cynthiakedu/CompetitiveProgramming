#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        m[i + 1] = x;
    }
    string s;
    cin >> s;
    int ans = 0;
    for (auto c : s) {
        ans += m[c - '0'];
    }
    cout << ans << endl;

    return 0;
}
