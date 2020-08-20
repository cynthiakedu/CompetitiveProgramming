#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K;
int arr[1000005];
int trie[50000000][2];
int num[50000000];
int ct = 1;

void add(int x) {
    int idx = 0;
    for (int i = 31; i >= 0; i--) {
        int dig = (x >> i) & 1;
        if (!trie[idx][dig]) {
            trie[idx][dig] = ct++;
        }
        num[trie[idx][dig]]++;
        idx = trie[idx][dig];
    }
}

ll count(int x) {
    int idx = 0;
    ll ret = 0;
    for (int i = 31; i >= 0; i--) {
        int d1 = (x >> i) & 1;
        int d2 = (K >> i) & 1;
        int d = d1 ^ d2;
        if (d2 == 0) {
            if (!trie[idx][1 - d]) {
                trie[idx][1 - d] = ct++;
            }
            ret += num[trie[idx][1 - d]];
        }
        if (!trie[idx][d]) {
            trie[idx][d] = ct++;
        }
        if (i == 0) ret += num[trie[idx][d]];
        idx = trie[idx][d];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 0;
    cin >> N >> K;
    add(0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (i >= 2) {
            arr[i] ^= arr[i - 1];
        }
        ans += count(arr[i]);
        add(arr[i]);
    }
    cout << ans << endl;

    return 0;
}
