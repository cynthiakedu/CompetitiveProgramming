#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int ct = 0;
ll N, M;
vector<ll> v;

ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ct++;
    if (x == 0) return y;
    v.push_back(y / x);
    return gcd(x, y % x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N >> M;
        if (!N && !M) return 0;

        ct = 0;
        v.clear();
        gcd(N, M);
        vector<int> w(v.size(), 0);
        w[v.size() - 1] = 1;
        for (int i = v.size() - 2; i >= 0; i--) {
            if (w[i + 1] == 0) {
                w[i] = 1;
            } else {
                w[i] = v[i] == 1 ? 0 : 1;
            }
        }
        cout << (w[0] ? "Stan" : "Ollie") << " wins" << endl;
    }

    return 0;
}
