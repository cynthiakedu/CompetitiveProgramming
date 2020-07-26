#include <bits/stdc++.h>
using namespace std;
int ans = 0;
string s;

int p(int a, int b) {
    if (b == 0) return 1;
    int x = p(a, b / 2);
    return x * x * (b % 2 == 1 ? a : 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i = 1; i <= s.size() - 1; i++) {
        ans += p(2, i);
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '7') {
            ans += p(2, s.size() - 1 - i);
        }
    }

    cout << ans + 1 << endl;
    return 0;
}
