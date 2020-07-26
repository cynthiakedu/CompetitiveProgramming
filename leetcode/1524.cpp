#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long dp[100005][2] = {};
        for (int i = 0; i < arr.size(); i++) {
            dp[i][0] = arr[i] % 2 == 0;
            dp[i][1] = arr[i] % 2 == 1;
            if (i == 0) continue;
            if (arr[i] % 2 == 0) {
                dp[i][0] = (dp[i][0] + dp[i - 1][0]) % (1000000007);
                dp[i][1] = (dp[i][1] + dp[i - 1][1]) % 1000000007;
            } else {
                dp[i][0] = (dp[i][0] + dp[i - 1][1]) % 1000000007;
                dp[i][1] = (dp[i][1] + dp[i - 1][0]) % 1000000007;
            }
        }

        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans = (ans + dp[i][1]) % 1000000007;
        }
        return ans;
    }
};