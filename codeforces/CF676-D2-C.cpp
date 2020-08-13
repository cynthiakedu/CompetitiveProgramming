#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K;
vector<int> v[2];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> s;
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) {
    }
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        int pos = (int)(upper_bound(v[1 - c].begin(), v[1 - c].end(), i) - v[1 - c].begin());
        int r = i, pos2 = pos + K;
        if (pos2 >= v[1 - c].size()) {
            r = s.size();
        } else {
            r = v[1 - c][pos2];
        }
        ans = max(ans, r - i);

        pos = (int)(lower_bound(v[c].begin(), v[c].end(), i) - v[c].begin());
        r = i, pos2 = pos + K;
        if (pos2 >= v[c].size()) {
            r = s.size();
        } else {
            r = v[c][pos2];
        }
        ans = max(ans, r - i);
    }
    cout << ans << endl;
    return 0;
}
