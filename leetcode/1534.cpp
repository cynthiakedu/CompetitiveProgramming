#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ct = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (int k = j + 1; k < arr.size(); k++) {
                    bool ok = true;
                    if (abs(arr[i] - arr[j]) > a) ok = false;
                    if (abs(arr[j] - arr[k]) > b) ok = false;
                    if (abs(arr[i] - arr[k]) > c) ok = false;
                    if (ok) ct++;
                }
            }
        }
        return ct;
    }
};