#include <bits/stdc++.h>
using namespace std;
string s;
int K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cin >> K;
    for (int i = 0; i < s.size() - 1; i++) {
        if (K == 0) break;
        int mx = s[i] - '0', mxIdx = i;
        for (int j = i + 1; j <= min(i + K, (int)s.size() - 1); j++) {
            if (s[j] - '0' > mx) {
                mx = s[j] - '0';
                mxIdx = j;
            }
        }
        for (int j = mxIdx - 1; j >= i; j--) {
            char a = s[j], b = s[j + 1];
            s[j] = b, s[j + 1] = a;
        }
        K -= (mxIdx - i);
    }

    cout << s << endl;
    return 0;
}
