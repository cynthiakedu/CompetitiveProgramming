#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int M, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;

    double ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += (pow(1.0 * i / M, N) - pow(1.0 * (i - 1) / M, N)) * i;
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
