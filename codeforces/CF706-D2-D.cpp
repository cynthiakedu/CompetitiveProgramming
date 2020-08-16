#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int trie[8000000][2];
int num[8000000];
int ct = 1;

int Q;
void change(int x, int add) {
    int idx = 0;
    for (int i = 30; i >= 0; i--) {
        int dig = (x >> i) & (1);
        if (trie[idx][dig] == 0) {
            trie[idx][dig] = ct++;
        }
        idx = trie[idx][dig];
        num[idx] += add;
    }
}

int getxor(int x) {
    int idx = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int dig = (x >> i) & (1);
        for (int j = 0; j <= 1; j++) {
            int j1 = ((1 - dig) + j) % 2;
            if (trie[idx][j1] && num[trie[idx][j1]]) {
                ans += (1 << i) * (j1 ^ dig);
                idx = trie[idx][j1];
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q;
    change(0, 1);
    for (int q = 0; q < Q; q++) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '+') {
            change(x, 1);
        } else if (type == '-') {
            change(x, -1);
        } else {
            cout << getxor(x) << endl;
        }
    }

    return 0;
}
