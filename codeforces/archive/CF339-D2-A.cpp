#include <bits/stdc++.h>
using namespace std;
string S;
vector<char> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    for (auto c : S) {
        if (c != '+') {
            v.push_back(c);
        }
    }
    sort(v.begin(), v.end());
    string ans = "";
    if (v.size() > 0) ans += v[0];
    for (int i = 1; i < v.size(); i++) {
        ans += '+';
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
