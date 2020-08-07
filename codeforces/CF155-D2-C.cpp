#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string S;
int K;
int bad[26];
int dp[26];
int dp2[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(bad, -1, sizeof bad);
    cin >> S;
    cin >> K;
    for (int i = 0; i < K; i++) {
        string x;
        cin >> x;
        bad[x[0] - 'a'] = x[1] - 'a';
        bad[x[1] - 'a'] = x[0] - 'a';
    }
    int ans = S.size();
    for (int i = 0; i < 26; i++) {
        dp[i] = S.size();
        dp2[i] = S.size();
    }

    for (int i = S.size() - 1; i >= 0; i--) {
        int c = S[i] - 'a';
        int ret = S.size() - i - 1;
        for (int j = 0; j < 26; j++) {
            if (j != bad[c]) {
                ret = min(ret, dp2[j] - i - 1 + dp[j]);
            }
        }
        dp[c] = ret;
        dp2[c] = i;
        ans = min(ans, i + dp[c]);
    }
    cout << ans << endl;

    return 0;
}
