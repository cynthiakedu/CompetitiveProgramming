#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int trie[1000005][26];
bool isWord[1000005];
int ct = 1;
int wordCt, typeCt;
int N;

void insertWord(string x) {
    int idx = 0;
    for (auto c : x) {
        if (trie[idx][c - 'a'] == 0) {
            trie[idx][c - 'a'] = ct++;
        }
        idx = trie[idx][c - 'a'];
    }
    isWord[idx] = true;
}

void count(int idx, int lenSoFar, bool isStart = true) {
    if (isWord[idx]) {
        wordCt++;
        typeCt += lenSoFar;
    }
    int childCt = isWord[idx];
    for (int i = 0; i < 26; i++) {
        if (trie[idx][i]) childCt++;
    }
    for (int i = 0; i < 26; i++) {
        if (trie[idx][i] == 0) continue;
        count(trie[idx][i], lenSoFar + (((!isStart) && (childCt == 1)) ? 0 : 1), false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N) {
        memset(trie, 0, sizeof trie);
        memset(isWord, false, sizeof isWord);
        ct = 1;
        wordCt = 0;
        typeCt = 0;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            insertWord(s);
        }
        count(0, 0);
        cout << fixed << setprecision(2) << (1.0 * typeCt / wordCt) << endl;
    }

    return 0;
}
