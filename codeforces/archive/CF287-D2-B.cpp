#include <bits/stdc++.h>
using namespace std;
int N, K;

bool can(int x) {
    int y = (N + 1 + x - 1) / (x);
    return y <= K - 1 && (N + 1) >= x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    int l = 1, r = N - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (can(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (can(l)) {
        cout << l << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
