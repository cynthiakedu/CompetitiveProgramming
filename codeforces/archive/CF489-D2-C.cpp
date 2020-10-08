#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int M, S;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> S;
    if (9 * M < S) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    if (S == 0) {
        if (M == 1) {
            cout << 0 << " " << 0 << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
        return 0;
    }
    int c1 = S, c2 = S;
    for (int i = M; i >= 1; i--) {
        int dig = max(i == M ? 1 : 0, c1 - 9 * (i - 1));
        c1 -= dig;
        s1 += (char)(dig + '0');
    }
    for (int i = M; i >= 1; i--) {
        int dig = min(9, c2);
        c2 -= dig;
        s2 += (char)(dig + '0');
    }
    cout << s1 << " " << s2 << endl;
    return 0;
}
