#include <bits/stdc++.h>
using namespace std;
int T, N;
string s;
map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}, {'<', '>'}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "Case " << t + 1 << ":" << endl;
        cin >> s;
        N = s.size();
        s += "..";
        int dp[100005] = {};
        for (int i = N - 1; i >= 0; i--) {
            int x = dp[i + 1];
            if (m[s[i]] == s[i + x + 1]) {
                dp[i] = dp[i + 1] + 2 + dp[i + x + 2];
            }
            // cout << "i " << i << " " << dp[i] << endl;
        }
        for (int i = 0; i < N; i++) {
            cout << dp[i] << endl;
        }
    }

    return 0;
}
