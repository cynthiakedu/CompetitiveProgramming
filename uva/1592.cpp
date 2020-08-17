#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int r, c;
string arr[10005][15];

void solve() {
    for (int i = 1; i <= c; i++) {
        for (int j = i + 1; j <= c; j++) {
            map<pair<string, string>, int> m;
            for (int k = 1; k <= r; k++) {
                string a = arr[k][i], b = arr[k][j];
                if (m.count({a, b}) > 0) {
                    cout << "NO" << endl;
                    cout << m[{a, b}] << " " << k << endl;
                    cout << i << " " << j << endl;
                    return;
                }
                m[{a, b}] = k;
            }
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> r) && (cin >> c)) {
        string s;
        getline(cin, s);
        for (int i = 1; i <= r; i++) {
            getline(cin, s);
            string x;
            int pos1 = 0;
            for (int j = 1; j <= c - 1; j++) {
                int pos2 = s.find(',', pos1);
                arr[i][j] = s.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
            }
            arr[i][c] = s.substr(pos1, s.size() - pos1);
        }
        solve();
    }
    return 0;
}
