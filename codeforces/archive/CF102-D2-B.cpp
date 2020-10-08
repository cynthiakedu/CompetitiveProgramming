#include <bits/stdc++.h>
using namespace std;
string s;
int n = 0;

int fd(int x) {
    int ct = 0;
    while (x > 0) {
        ct += x % 10;
        x /= 10;
    }
    return ct;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int dig = 0;
    for (auto c : s) {
        n += c - '0';
        dig++;
    }
    int ans = 0;
    while (n >= 10) {
        ans++;
        n = fd(n);
    }
    cout << ans + (dig == 1 ? 0 : 1) << endl;

    return 0;
}
