#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, K, P, Q, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> Q;
    if (K == 0) {
        for (ll i = 0; i < Q; i++) {
            cin >> q;
            cout << '.';
        }
        cout << endl;
        return 0;
    }
    ll amt = min(K, N - K);
    if ((N - K - amt) % 2 == 1 && amt > 1) amt--;
    ll a = N - K - amt + 1, b = K - amt;

    // cout << "amt " << amt << endl;
    // cout << "A b " << a << " " << b << endl;
    for (ll i = 0; i < Q; i++) {
        cin >> q;
        if (q >= N - b + 1) {
            cout << 'X';
        } else if (q <= a) {
            cout << '.';
        } else {
            q -= a;
            cout << (q % 2 == 1 ? 'X' : '.');
        }
    }
    cout << endl;

    return 0;
}

// 8 5 8
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
