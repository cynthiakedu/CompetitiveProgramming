#include <bits/stdc++.h>
using namespace std;

string s;
int idx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    string wd = "";
    vector<string> ans;
    while (idx < s.size()) {
        if (idx >= s.size() - 2) {
            wd += s[idx];
            idx++;
        } else {
            if (s.substr(idx, 3) == "WUB") {
                if (wd.size() > 0) {
                    ans.push_back(wd);
                    wd = "";
                }
                idx += 3;
            } else {
                wd += s[idx];
                idx++;
            }
        }
    }
    if (wd.size() > 0) {
        ans.push_back(wd);
        wd = "";
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    return 0;
}
