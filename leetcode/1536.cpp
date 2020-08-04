#include <bits/stdc++.h>
using namespace std;

//from tmwilliamlin168
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> v(N);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            while (v[i] < N && grid[i][N - 1 - v[i]] == 0) {
                v[i]++;
            }
        }
        for (int i = 0; i < N; i++) {
            int j = i;
            while (j < N && v[j] < N - 1 - i) {
                j++;
            }
            if (j >= N) return -1;
            ans += j - i;
            while (j > i) {
                swap(v[j], v[j - 1]);
                j--;
            }
        }
        return ans;
    }
};