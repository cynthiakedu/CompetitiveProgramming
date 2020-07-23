#include <bits/stdc++.h>
using namespace std;
int N;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int t = 0; t < N; t++) {
        cin >> s1 >> s2;
        int mx = max(s1.size(), s2.size());
        int a1[205] = {}, a2[205] = {}, c[205] = {}, ans[205] = {};
        for (int i = 0; i < s1.size(); i++) a1[i] = s1[i] - '0';
        for (int i = 0; i < s2.size(); i++) a2[i] = s2[i] - '0';
        for (int i = 0; i < mx; i++) {
            int ct = a1[i] + a2[i] + c[i];
            ans[i] += ct % 10;
            c[i + 1] = (ct - ct % 10) / 10;
        }
        ans[mx] = c[mx];
        if (ans[mx] > 0) mx++;
        bool ok = false;

        for (int i = 0; i < mx; i++) {
            if (ans[i] == 0 && ok) {
                cout << ans[i];
            } else if (ans[i] != 0) {
                ok = true;
                cout << ans[i];
            }
        }
        cout << endl;
    }

    return 0;
}
