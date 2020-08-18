#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int trie[10000000][2];
ll ct[10000000];
int num = 1;

void add(int x) {
    int idx = 0;
    for (int i = 30; i >= 0; i--) {
        int dig = (x >> i) & (1);
        if (!trie[idx][dig]) {
            trie[idx][dig] = num++;
        }
        idx = trie[idx][dig];
        ct[idx]++;
    }
}

int getLarge(int x) {
    int idx = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        int dig = (x >> i) & (1);
        if (!trie[idx][dig]) {
            trie[idx][dig] = num++;
        }
        if (!trie[idx][1 - dig]) {
            trie[idx][1 - dig] = num++;
        }
        if (ct[trie[idx][dig]] >= (1 << i)) {
            dig = 1 - dig;
        }
        res += dig * (1 << i);
        idx = trie[idx][dig];
    }
    return x ^ res;
}

int N, Q, arr[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    set<int> S;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        S.insert(x);
    }
    for (auto x : S) add(x);
    for (int i = 1; i <= Q; i++) {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
        cout << getLarge(arr[i]) << endl;
    }

    return 0;
}
