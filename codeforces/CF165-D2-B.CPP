#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K;

bool can(int v) {
    ll ans = v;
    while (v > 0) {
        ans += (v / K);
        v /= K;
    }
    if (ans >= N) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int l = 1, r = 1000000000;
    while (l < r) {
        int m = (l + r) / 2;
        if (can(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}
