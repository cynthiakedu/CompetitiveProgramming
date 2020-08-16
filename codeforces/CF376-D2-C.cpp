#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
map<int, bool> m{{1, false}, {6, false}, {8, false}, {9, false}};
vector<int> v;
int ct0 = 0;

string s;

int m7(string x) {
    if (x.size() == 0) return 0;
    int cur = 1;
    int ret = 0;
    for (int i = x.size() - 1; i >= 0; i--) {
        ret = (ret + ((x[i] - '0') * cur) % 7) % 7;
        cur = (cur * 10) % 7;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (auto c1 : s) {
        int c = c1 - '0';
        if (m.count(c)) {
            if (m[c]) {
                v.push_back(c);
            }
            m[c] = true;
        } else if (c == 0) {
            ct0++;
        } else {
            v.push_back(c);
        }
    }
    string s1 = "";
    for (auto x : v) s1 += string(1, (char)('0' + x));
    s1 += "0000";
    for (int i = 0; i < ct0; i++) s1 += "0";

    vector<char> v1 = {'1', '6', '8', '9'};
    do {
        for (int i = 0; i < 4; i++) {
            s1[v.size() + i] = v1[i];
        }
        if (m7(s1) == 0) {
            cout << s1 << endl;
            return 0;
        }
    } while (next_permutation(v1.begin(), v1.end()));

    return 0;
}
