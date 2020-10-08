#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
vector<char> v1;
vector<int> v2;
string ans = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int idx = 0;
    while (idx < s.size()) {
        int j = idx;
        while (j < s.size() && s[j] == s[idx]) j++;
        int amt = j - idx;
        if (amt >= 3) amt = 2;
        v1.push_back(s[idx]);
        v2.push_back(amt);
        idx = j;
    }
    int i2 = 0;
    while (i2 < v2.size()) {
        if (v2[i2] == 1) {
            ans += v1[i2];
            i2++;
            continue;
        }
        int j = i2;
        while (j < v2.size() && v2[j] == v2[i2]) j++;
        for (int k = i2; k < j; k++) {
            ans += v1[k];
            if ((k - i2) % 2 == 0) {
                ans += v1[k];
            }
        }
        i2 = j;
    }
    cout << ans << endl;

    return 0;
}
