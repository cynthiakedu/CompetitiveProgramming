#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
string s;
int ans = 0;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        ans = 0;
        v = {0};
        cin >> s;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'A';
            ans += min(c, (26 - c) % 26);
            if (c != 0) v.push_back(i);
        }
        v.push_back((int)s.size());
        int temp = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            int a = v[i], b = ((int)s.size()) - v[i + 1];
            temp = min(temp, 2 * (a + b) - max(a, b));
        }
        cout << ans + temp << endl;
    }

    return 0;
}
