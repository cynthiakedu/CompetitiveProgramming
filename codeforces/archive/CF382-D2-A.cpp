#include <bits/stdc++.h>
using namespace std;
string s;
string t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '|') {
            idx = i;
            break;
        }
    }
    int l = idx, r = s.size() - idx - 1;
    int diff = abs(l - r);
    if (t.size() < diff || (t.size() - diff) % 2 == 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int x = (t.size() - diff) / 2;
    int amt = l <= r ? x + diff : x;

    string a = s.substr(0, l), b = s.substr(idx + 1, r);
    a += t.substr(0, amt);
    b += t.substr(amt, t.size() - amt);
    cout << a << "|" << b << endl;

    return 0;
}
