#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N, I;
long double p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> p >> I;
        if (p == 0) {
            cout << fixed << setprecision(4) << 0.0 << endl;
        } else {
            long double ret = p * pow(1 - p, 1.0 * (I - 1)) / (1 - pow(1 - p, 1.0 * N));
            cout << fixed << setprecision(4) << ret << endl;
        }
    }

    return 0;
}
