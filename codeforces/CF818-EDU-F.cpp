#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int Q;
ll N;
ll getRes(ll num) {
    ll b = (N - num) * (N - num - 1) / 2;
    b = min(b, num);
    return b + num;
}

bool can(ll num) {
    return getRes(num + 1) <= getRes(num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> N;
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        ll l = 1, r = N - 2;
        while (l < r) {
            ll m = (l + r) / 2;
            bool ok = can(m);
            if (ok) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << getRes(l) << endl;
    }

    return 0;
}

// 6
// 3
// 4
// 6
// 1
// 2
// 10
