#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int trie[3200000][2];
int num[6500000];
int id = 1;
int Q;
void add(int x, int v) {
    int idx = 0;
    for (int i = 30; i >= 0; i--) {
        int d = (x >> i) & (1);
        if (trie[idx] == 0) {
            trie[idx][d] = id++;
        }
        num[trie[idx][d]] += v;
        idx = trie[idx][d];
    }
}

int ct(int x, int l) {
    int idx = 0;
    int ret = 0;
    for (int i = 30; i >= 0; i--) {
        int d = (x >> i) & (1);
        int d2 = (l >> i) & (1);
        for (int j = 0; j < 2; j++) {
            if (trie[idx][j] == 0) {
                trie[idx][j] = id++;
            }
        }

        if (d2 == 1) {
            ret += num[trie[idx][1 - d2 ^ d]];
        }
        idx = trie[idx][d2 ^ d];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int type, p;
        cin >> type >> p;
        if (type == 1) {
            add(p, 1);
        } else if (type == 2) {
            add(p, -1);
        } else {
            int l;
            cin >> l;
            cout << ct(p, l) << "\n";
        }
    }

    return 0;
}

// 3
// 1 3
// 1 4
// 3 6 3
