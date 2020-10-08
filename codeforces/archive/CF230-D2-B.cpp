#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
set<ll> primes;
bool vis[1000005];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 2; i < 1000005; i++) {
        if (vis[i]) continue;
        primes.insert(i);
        for (ll j = i; j < 1000005; j += i) vis[j] = true;
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        ll y = sqrt(x);
        if (y * y != x || primes.count(y) == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
