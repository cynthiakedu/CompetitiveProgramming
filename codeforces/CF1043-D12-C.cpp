#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int ans[1005];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int l = 0, r = s.size() - 1;

    while (l <= r) {
        int mn = INT_MAX, mnIdx = -1;
        for (int i = r; i >= l; i--) {
            if (s[i] - 'a' < mn) {
                mn = s[i] - 'a';
                mnIdx = i;
            }
        }
        v.push_back(mnIdx);
        r = mnIdx - 1;
    }
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) ans[v[i]] = 1 - ans[v[i]];
    for (int i = 1; i < v.size(); i++) ans[v[i] - 1] = 1 - ans[v[i] - 1];

    for (int i = 0; i < s.size(); i++) {
        cout << ans[i] << (i == s.size() - 1 ? "\n" : " ");
    }

    return 0;
}
