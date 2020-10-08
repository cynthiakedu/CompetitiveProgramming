#include <bits/stdc++.h>
using namespace std;
int N;
string a;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> a;
    for (auto c : a) {
        if (c == '0') continue;
        int x = c - '0';
        if (x == 2 || x == 3 || x == 5 || x == 7) m[x]++;
        if (x == 4) m[2] += 2, m[3]++;
        if (x == 6) m[3]++, m[5]++;
        if (x == 8) m[2] += 3, m[7]++;
        if (x == 9) m[3] += 2, m[2]++, m[7]++;
    }
    string ans = "";
    for (int i = 9; i >= 2; i--) {
        for (int j = 0; j < m[i]; j++) {
            ans = ans + (char)('0' + i);
        }
    }
    cout << ans << endl;

    return 0;
}
