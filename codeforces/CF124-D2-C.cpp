#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

bool isPrime[1005];
bool vis[1005];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 1005; i++) {
        if (vis[i]) continue;
        isPrime[i] = true;
        for (int j = i; j < 1005; j += i) {
            vis[j] = true;
        }
    }
    char mstc;
    int mst = 0;
    map<char, int> m;
    cin >> s;
    int S = s.size();

    int ct1 = 0;
    for (int i = 1; i <= S; i++) {
        if (i == 1) ct1++;
        if (isPrime[i] && 2 * i > S) ct1++;
    }

    for (auto c : s) m[c]++;
    for (auto p : m) {
        if (p.second > mst) {
            mst = p.second;
            mstc = p.first;
        }
    }
    if (mst < s.size() - ct1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<char> v;
    for (int i = 0; i < mst - (s.size() - ct1); i++) v.push_back(mstc);
    for (auto p : m) {
        if (p.first != mstc) {
            for (int i = 0; i < p.second; i++) v.push_back(p.first);
        }
    }
    int idx = 0;
    cout << "YES" << endl;
    for (int i = 1; i <= s.size(); i++) {
        if (i == 1 || (isPrime[i] && 2 * i > S)) {
            cout << v[idx];
            idx++;
        } else {
            cout << mstc;
        }
    }
    cout << endl;

    return 0;
}
