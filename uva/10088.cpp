#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
typedef complex<ll> P;
#define X real()
#define Y imag()

P arr[1005];
int N;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> N;
        if (N == 0) return 0;
        for (int i = 0, a, b; i < N; i++) {
            cin >> a >> b;
            arr[i] = P{a, b};
        }
        double area = 0;
        for (int i = 0; i < N; i++) {
            area += (double)(conj(arr[i]) * arr[(i + 1) % N]).Y;
        }
        area = 1.0 * abs(area) / 2;
        ll ct = N;
        for (int i = 0; i < N; i++) {
            P a = arr[i], b = arr[(i + 1) % N];
            ll g = gcd(abs(a.X - b.X), abs(a.Y - b.Y));
            ct += g - 1;
        }
        cout << (ll)(area + 1 - 1.0 * ct / 2) << endl;
    }

    return 0;
}
