#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N;
string S[15];
int A[15], B[15];

bool chk(string a, string b, int x, int y) {
    set<char> as, bs, both;
    for (auto c : a) as.insert(c);
    for (auto c : b) bs.insert(c);
    for (int i = 0; i <= 9; i++) {
        char c = (char)('0' + i);
        if (as.count(c) > 0 && bs.count(c) > 0) both.insert(c);
    }
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) {
            ct2++;
            both.erase(a[i]);
        }
    }
    return (y == both.size()) && (x == ct2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> A[i] >> B[i];
    }
    vector<string> ans;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    set<int> s;
                    s.insert({i, j, k, l});
                    if (s.size() < 4) continue;
                    string x = to_string(i) + to_string(j) + to_string(k) + to_string(l);
                    bool ok = true;
                    for (int i = 0; i < N; i++) {
                        ok = ok && chk(x, S[i], A[i], B[i]);
                    }
                    if (ok) ans.push_back(x);
                }
            }
        }
    }
    if (ans.size() == 0) {
        cout << "Incorrect data" << endl;
    } else if (ans.size() > 1) {
        cout << "Need more data" << endl;
    } else {
        cout << ans[0] << endl;
    }

    return 0;
}
