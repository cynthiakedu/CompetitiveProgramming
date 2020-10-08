#include <bits/stdc++.h>
using namespace std;
string s;
string t;
map<char, int> sm;
map<char, int> tmap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    for (auto c : s) sm[c]++;
    for (auto c : t) tmap[c]++;

    for (auto c : tmap) {
        if (sm.count(c.first) == 0) {
            cout << "need tree" << endl;
            return 0;
        }
    }
    bool ok = true;
    for (auto p : sm) {
        int a = sm[p.first], b = tmap[p.first];
        if (a < b) {
            cout << "need tree" << endl;
            return 0;
        }
        if (a > b) {
            ok = false;
        }
    }
    if (ok) {
        cout << "array" << endl;
    } else {
        int i1 = 0, i2 = 0;
        for (int i = 0; i < t.size(); i++) {
            while (i2 < s.size() && s[i2] != t[i]) {
                i2++;
            }
            if (i2 == s.size()) {
                cout << "both" << endl;
                return 0;
            }
            i2++;
        }

        cout << "automaton" << endl;
    }

    return 0;
}
