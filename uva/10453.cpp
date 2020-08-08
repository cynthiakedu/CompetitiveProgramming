#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

string s;
int dp[1005][1005];
string dp2[1005][1005];

pair<int, string> solve(int l, int r) {
    if (r < l) return {0, ""};
    if (r == l) return {0, string(1, s[l])};
    if (dp[l][r] != -1) return {dp[l][r], dp2[l][r]};

    pair<int, string> p1 = solve(l + 1, r);
    int ans1 = p1.first + 1;
    string ans2 = "" + string(1, s[l]) + p1.second + string(1, s[l]);

    p1 = solve(l, r - 1);
    if (p1.first + 1 < ans1) {
        ans1 = p1.first + 1;
        ans2 = "" + string(1, s[r]) + p1.second + string(1, s[r]);
    }

    if (s[l] == s[r]) {
        pair<int, string> p2 = solve(l + 1, r - 1);
        if (p2.first < ans1) {
            ans1 = p2.first;
            ans2 = string(1, s[l]) + p2.second + string(1, s[r]);
        }
    }
    dp[l][r] = ans1;
    dp2[l][r] = ans2;
    cout << "solve " << l << " " << r << " " << ans1 << " " << ans2 << endl;
    return {ans1, ans2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s) {
        memset(dp, -1, sizeof dp);
        pair<int, string> p = solve(0, s.size() - 1);
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
