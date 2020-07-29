#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (true) {
        getline(cin, s1);
        if (s1 == "#") return 0;
        getline(cin, s2);
        ct++;
        int dp[105][105] = {};
        int N1 = s1.size(), N2 = s2.size();
        for (int i = N1; i >= 0; i--) {
            for (int j = N2; j >= 0; j--) {
                if (i == N1 || j == N2) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                if (s1[i] == s2[j]) dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
            }
        }
        cout << "Case #" << ct << ": you can visit at most " << dp[0][0] << " cities." << endl;
    }

    return 0;
}
