#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int ct = 0;
        for (int i = 0; i < target.size(); i++) {
            if ((target[i] - '0') % 2 != ct % 2) {
                ct++;
            }
        }
        return ct;
    }
};