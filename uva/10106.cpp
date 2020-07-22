#include <bits/stdc++.h>
using namespace std;
string X, Y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> X) && (cin >> Y)) {
        int res[505] = {}, maxDig = 0;
        for (int i = 0; i < Y.size(); i++) {
            for (int j = 0; j < X.size(); j++) {
                int a = Y[Y.size() - 1 - i] - '0', b = X[X.size() - 1 - j] - '0';
                res[i + j] += a * b;
            }
        }
        for (int i = 0; i < 504; i++) {
            if (res[i] > 0) maxDig = max(maxDig, i);
            if (res[i] >= 10) {
                res[i + 1] += res[i] / 10;
                res[i] %= 10;
            }
        }
        string ans = "";

        for (int i = 0; i <= maxDig; i++) {
            ans = (char)(res[i] + '0') + ans;
        }
        cout << ans << endl;
    }

    return 0;
}
