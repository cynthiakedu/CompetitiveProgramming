#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<int> primes;
bool vis[100005];
ll N;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 100005; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 100005; j += i) {
            vis[j] = true;
        }
    }

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        int g = 0;
        for (auto x : primes) {
            int ct = 0;
            while (N % x == 0) {
                ct++;
                N /= x;
            }
            if (ct > 0) g = gcd(g, ct);
        }
        if (N > 1) g = 1;
        cout << g << endl;
    }

    return 0;
}
