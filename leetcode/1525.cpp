#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSplits(string s) {
        map<char, int> l;
        map<char, int> r;
        int inc[100005] = {}, dec[100005] = {};
        for (int i = 0; i < s.size(); i++) {
            if (l.count(s[i]) == 0) inc[i]++;
            l[s[i]] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (r.count(s[i]) == 0) dec[i]++;
            r[s[i]] = 1;
        }

        int ans = 0;
        int ct1 = 0, ct2 = l.size();

        for (int i = 0; i < s.size() - 1; i++) {
            if (inc[i] == 1) ct1++;
            if (dec[i] == 1) ct2--;
            if (ct1 == ct2) ans++;
        }
        return ans;
    }
};