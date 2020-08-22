#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int C, D, N;
string T;
int cum[26][10005];
string s;

bool solve() {
    cin >> s;
    int idx = 0;
    vector<int> v1;
    vector<char> v2;
    string temp = "";
    for (int i = 0; i < (int)s.size(); i++) {
        if (isdigit(s[i])) {
            temp += s[i];
        } else {
            v1.push_back(stoi(temp));
            temp = "";
            v2.push_back(s[i]);
        }
    }
    for (int j = 0; j < (int)v1.size(); j++) {
        bool ok = false;
        int a = v1[j], b = v2[j] - 'A';
        int need = cum[b][idx] + a;
        int pos = (int)(lower_bound(cum[b] + idx + 1, cum[b] + N + 1, need) - cum[b]);
        if (pos >= N + 1) return false;
        idx = pos;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> C;

    for (int c = 0; c < C; c++) {
        memset(cum, 0, sizeof cum);
        cin >> D;
        cin >> T;
        N = (int)T.size();
        for (int i = 1; i <= N; i++) {
            cum[T[i - 1] - 'A'][i] += 1;
            for (int j = 0; j < 26; j++) {
                cum[j][i] += cum[j][i - 1];
            }
        }
        for (int i = 0; i < D; i++) {
            cout << (solve() ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}
