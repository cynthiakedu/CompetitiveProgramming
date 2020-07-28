#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    cin >> N;
    for (auto x : primes) {
        int ct = 0;
        while (N % x == 0) {
            ct++;
            N /= x;
        }
        if (ct > 0) N *= x;
    }
    cout << N << endl;
    return 0;
}
