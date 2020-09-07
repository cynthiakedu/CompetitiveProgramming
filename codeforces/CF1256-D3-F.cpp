#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int Q, N;
string s[2];
int ct[2][26];

void solve() {
    cin >> N;
    cin >> s[0] >> s[1];
    memset(ct, 0, sizeof ct);
    for (int i = 0; i < 2; i++) {
        for (int c : s[i]) {
            ct[i][c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (ct[0][i] != ct[1][i]) {
            cout << "NO" << endl;
            return;
        }
    }
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (s[0][i] != s[1][i]) num++;
    }
    cout << (num % 2 == 0 ? "NO" : "YES") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        solve();
    }

    return 0;
}
