#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int trie[100005][10];
bool isPhone[100005];
int ct = 1;
int T, N;
string s;
vector<string> v;

void insertPhone(string x) {
    int idx = 0;
    for (auto c : x) {
        if (trie[idx][c - '0'] == 0) {
            trie[idx][c - '0'] = ct++;
        }
        idx = trie[idx][c - '0'];
    }
    isPhone[idx] = true;
}

bool hasPrefix(string x) {
    int idx = 0;
    for (int i = 0; i < x.size() - 1; i++) {
        idx = trie[idx][x[i] - '0'];
        if (isPhone[idx]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(trie, 0, sizeof trie);
        memset(isPhone, false, sizeof isPhone);
        ct = 1;
        v.clear();

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> s;
            insertPhone(s);
            v.push_back(s);
        }
        bool ok = true;
        for (auto x : v) {
            if (hasPrefix(x)) {
                cout << "NO" << endl;
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        }
    }

    return 0;
}
