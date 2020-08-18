#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 350000;
int T;
string s;
int ct[mxN + 5], l[mxN + 5], sz[mxN + 5];
int cumCt, cumLen;
int id = 1;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cumCt = 0;
        cumLen = 0;
        id = 1;
        ans = 0;

        cin >> s;
        stack<ii> S;
        for (auto c : s) {
            if (c == '(') {
                cumCt++;
                cumLen++;
                S.push({0, id});
                ct[id] = cumCt;
                l[id] = cumLen;
                id++;
            } else if (c == ')') {
                cumCt--;
                cumLen++;
                int mx = 0;
                while (S.top().first == 1) {
                    ii x = S.top();
                    S.pop();
                    mx = max(mx, x.second);
                }
                ii x = S.top();
                S.pop();
                int parity = ct[x.second];
                int curLen = cumLen - l[x.second];
                int curHeight = mx + 1;
                ans += (parity % 2 == 1 ? 1 : -1) * (ll)curLen * curHeight;
                S.push({1, mx + 1});
            }
        }
        cout << ans << endl;
    }

    return 0;
}
