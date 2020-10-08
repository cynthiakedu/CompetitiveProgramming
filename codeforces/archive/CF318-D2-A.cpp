#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    if (K <= (N + 1) / 2) {
        cout << 1 + 2 * (K - 1) << endl;
    } else {
        K -= (N + 1) / 2;
        cout << 2 * K << endl;
    }

    return 0;
}
