#include <bits/stdc++.h>
using namespace std;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    string ans = "";
    for (int i = 0; i < S.size(); i++) {
        ans += S[i];
    }
    for (int i = S.size() - 1; i >= 0; i--) {
        ans += S[i];
    }
    cout << ans << endl;

    return 0;
}
