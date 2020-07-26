#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sz(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
    int getLengthOfOptimalCompression(string s, int k) {
        int dp[105][105] = {}, N = s.size();
        for (int i = N; i >= 0; i--) {
            for (int k1 = 0; k1 <= k; k1++) {
                if (i == N || N - i <= k1) {
                    dp[i][k1] = 0;
                    continue;
                }
                int& cd = dp[i][k1];
                cd = N;
                int ct[26] = {}, most = 0;
                for (int j = i; j < N; j++) {
                    most = max(most, ++ct[s[j] - 'a']);
                    int amt = j - i + 1 - most;
                    if (amt > k1) continue;
                    cd = min(cd, 1 + sz(most) + dp[j + 1][k1 - amt]);
                }
            }
        }
        return dp[0][k];
    }
};