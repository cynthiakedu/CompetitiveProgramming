#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int trie[600000][26];
bool isWord[600000];
int ct = 1;
vector<string> v;
int N, M;

void insertWord(string x) {
    int idx = 0;
    for (auto c : x) {
        if (trie[idx][c - 'a'] == 0) {
            trie[idx][c - 'a'] = ct;
            ct++;
        }
        idx = trie[idx][c - 'a'];
    }
    isWord[idx] = true;
}

void dfs(string pre, int idx, bool include = false) {
    if (isWord[idx] && include) v.push_back(pre);
    for (int i = 0; i < 26; i++) {
        if (trie[idx][i] == 0) continue;
        dfs(pre + string(1, (char)('a' + i)), trie[idx][i], true);
    }
}

void search(string x) {
    int idx = 0;
    for (auto c : x) {
        if (trie[idx][c - 'a'] == 0) {
            return;
        }
        idx = trie[idx][c - 'a'];
    }
    dfs(x, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insertWord(s);
    }
    cin >> M;
    for (int i = 1; i <= M; i++) {
        v.clear();
        string s;
        cin >> s;
        search(s);
        cout << "Case #" << i << ":" << endl;
        if (v.size() == 0) {
            cout << "No match." << endl;
        } else {
            for (auto x : v) cout << x << endl;
        }
    }

    return 0;
}
