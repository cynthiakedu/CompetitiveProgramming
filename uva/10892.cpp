#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N;
vector<ll> primes;
bool vis[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < 1000005; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 1000005; j += i) {
            vis[j] = true;
        }
    }

    while (true) {
        cin >> N;
        ll N1 = N;
        if (N == 0) return 0;
        ll ans = 1;
        for (auto x : primes) {
            ll ct = 0;
            while (N % x == 0) {
                N /= x;
                ct++;
            }
            ans *= (2 * ct + 1);
        }
        if (N > 1) ans *= 3;
        cout << N1 << " " << (ans + 1) / 2 << endl;
    }

    return 0;
}
