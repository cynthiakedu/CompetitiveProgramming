#include <bits/stdc++.h>
using namespace std;
int N, K, T, D;
int one = 0, both = 0;
int oneT = -1, bothT = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T >> K >> D;
    for (int i = 1; i <= N * T; i++) {
        if (i % T == 0) {
            one += K;
            both += K;
        }
        if (i > D && (i - D) % T == 0) {
            both += K;
        }
        if (both >= N && bothT == -1) bothT = i;
        if (one >= N) {
            oneT = i;
            break;
        }
    }
    cout << (bothT < oneT ? "YES" : "NO") << endl;

    return 0;
}
