#include <bits/stdc++.h>
using namespace std;
string s, s1;
string ans = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int ct0 = 0, ct1 = 0;
    int idx = 0;
    for (auto c : s) {
        if (c != '1') {
            s1 += c;
        } else {
            ct1++;
        }
    }
    while (idx < s1.size() && s1[idx] != '2') {
        idx++;
    }
    string s2 = "";
    for (int i = 0; i < ct1; i++) s2 += '1';
    ans = s1.substr(0, idx) + s2 + s1.substr(idx, s.size() - idx);
    cout << ans << endl;

    return 0;
}
