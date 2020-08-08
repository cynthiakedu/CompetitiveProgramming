#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
unordered_map<string, bool> S;
bool ok = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        vector<string> V;
        vector<int> v;
        int mn = INT_MAX, idx = 0, idx2 = 0;
        vector<int> indices;
        for (int j = 0; j < 6; j++) {
            cin >> x;
            if (x < mn) {
                mn = x;
                idx = j;
            }
            if (x == mn) {
                idx2 = j;
            }
            v.push_back(x);
        }
        for (int j = 0; j < 6; j++) {
            if (v[j] == mn) indices.push_back(j);
        }
        for (int ind : indices) {
            string s1 = to_string(v[ind]);
            for (int k = 1; k < 6; k++) {
                s1 += "|" + to_string(v[(ind + k) % 6]);
            }
            string s2 = to_string(v[ind]);
            for (int k = 1; k < 6; k++) {
                s2 += "|" + to_string(v[(ind - k + 6) % 6]);
            }
            V.push_back(s1);
            V.push_back(s2);
        }
        for (auto s1 : V) {
            if (S.count(s1) > 0) ok = true;
        }
        for (auto s1 : V) {
            S[s1] = true;
        }
    }
    cout << (ok ? "Twin snowflakes found." : "No two snowflakes are alike.") << endl;

    return 0;
}

// 2
// 1 2 3 4 5 6
// 5 4 3 2 1 6