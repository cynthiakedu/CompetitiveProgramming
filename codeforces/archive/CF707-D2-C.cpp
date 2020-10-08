#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if (N == 1 || N == 2) {
        cout << -1 << endl;
        return 0;
    }
    ll s = N / 2;
    if (N % 2 == 1) {
        cout << (2 * s * (s + 1)) << " " << (s * s + (s + 1) * (s + 1)) << endl;
    } else {
        cout << (s * s - 1) << " " << s * s + 1 << endl;
    }

    return 0;
}
