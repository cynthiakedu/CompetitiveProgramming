#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
string s;
map<char, int> m;
int ans = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        m.clear();
        ans = INT_MAX;
        cin >> s;
        for (auto c : s) {
            m[c]++;
            ans = min(ans, (int)s.size() - m[c]);
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == j) continue;
                int a = -1, b = 0;
                for (auto c : s) {
                    if (c == (char)('0' + i)) {
                        a = b + 1;
                    }
                    if (c == (char)('0' + j)) {
                        if (a != -1) {
                            b = a + 1;
                        }
                    }
                }
                ans = min(ans, (int)s.size() - b);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
