#include <bits/stdc++.h>
using namespace std;

string S;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    int ct = 0;
    for (auto c : S) {
        if (c == '1') {
            ct++;
        }
    }
    if (S.size() == 1 && ct == 0) {
        cout << 0 << endl;
    } else {
        cout << ((S.size() + 1) / 2 - (ct == 1 && S.size() % 2 == 1 ? 1 : 0)) << endl;
    }
    return 0;
}
