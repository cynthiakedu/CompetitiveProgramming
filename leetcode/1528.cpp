#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char s1[105];
        for (int i = 0; i < s.size(); i++) {
            s1[indices[i]] = s[i];
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans += s1[i];
        }
        return ans;
    }
};