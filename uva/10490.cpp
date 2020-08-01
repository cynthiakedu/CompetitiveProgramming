#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ii pair<int, int>
ll N;
set<int> primes;
bool vis[60];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 60; i++) {
        if (vis[i]) continue;
        primes.insert(i);
        for (int j = i; j < 60; j += i) {
            vis[j] = true;
        }
    }
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        set<int> s{2, 3, 5, 7, 13, 17, 19, 31};
        if (s.count(N)) {
            ll num = (1LL << (N - 1)) * ((1LL << N) - 1);
            cout << "Perfect: " << num << "!" << endl;
        } else {
            if (primes.count(N)) {
                cout << "Given number is prime. But, NO perfect number is available." << endl;
            } else {
                cout << "Given number is NOT prime! NO perfect number is available." << endl;
            }
        }
    }

    return 0;
}

// 8589869056
