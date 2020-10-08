#include <bits/stdc++.h>
using namespace std;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    if (S.size() < 26) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i <= S.size() - 26; i++) {
        bool alph[26] = {};
        bool ok = true;
        for (auto c : S.substr(i, 26)) {
            if (c != '?') {
                if (alph[c - 'A'] == true) ok = false;
                alph[c - 'A'] = true;
            }
        }
        if (!ok) continue;
        vector<char> v;
        for (int j = 0; j < 26; j++) {
            if (!alph[j]) {
                v.push_back((char)('A' + j));
            }
        }
        string t = S;
        int ct = 0;
        for (int j = i; j < i + 26; j++) {
            if (t[j] == '?') {
                t[j] = v[ct];
                ct++;
            }
        }
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == '?') {
                t[j] = 'A';
            }
        }
        cout << t << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}
