#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;

vector<int> primes;
bool vis[100005];

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

    while ((cin >> N && cin >> M)) {
        bool ok = true;
        int M1 = M;
        for (auto x : primes) {
            int ct = 0, ctn = 0;
            while (M1 % x == 0) {
                ct += 1, M1 /= x;
            }
            int power = x;
            while (N >= power) {
                ctn += N / power;
                power *= x;
            }
            if (ct > ctn) {
                ok = false;
                break;
            }
            if (x > M) break;
        }
        if (M1 > 1 && N < M1) ok = false;
        if (ok) {
            cout << M << " divides " << N << "!" << endl;
        } else {
            cout << M << " does not divide " << N << "!" << endl;
        }
    }

    return 0;
}
