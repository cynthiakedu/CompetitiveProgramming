#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
ll arr[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int n = 1; n <= 100; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 || k == n) {
                arr[n][k] = 1;
            } else {
                arr[n][k] = arr[n - 1][k - 1] + arr[n - 1][k];
            }
        }
    }

    while (true) {
        cin >> N >> M;
        if (!N && !M) return 0;
        cout << N << " things taken " << M << " at a time is " << arr[N][M] << " exactly." << endl;
    }
    return 0;
}
