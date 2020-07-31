#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> primes;
bool vis[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= 100005; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j <= 100005; j += i) {
            vis[j] = true;
        }
    }

    while (true) {
        cin >> N;
        int N1 = N;
        if (N == 0) return 0;
        N = abs(N);
        vector<int> v;
        if (N1 < 0) v.push_back(-1);
        for (auto x : primes) {
            if (N % x == 0) {
                while (N % x == 0) {
                    v.push_back(x);
                    N /= x;
                }
            }
        }
        if (N > 1) {
            v.push_back(N);
        }
        cout << N1 << " = ";
        for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " x ");
    }

    return 0;
}
