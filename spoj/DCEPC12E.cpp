#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll arr[2][105][105], N, Q;
ll arr2[2][105];
ll S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> arr[t][i][j];
            }
        }
        for (int i = 1; i <= N; i++) {
            ll s = 0;
            for (int j = 1; j <= N; j++) {
                arr2[t][i] += arr[t][t ? i : j][t ? j : i];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                S += arr[0][i][k] * arr[1][k][j];
            }
        }
    }

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        char c;
        ll t, i, j, k;
        cin >> c >> i >> j >> k;
        i++;
        j++;
        t = c - 'A';

        ll diff = k - arr[t][i][j];
        diff *= arr2[1 - t][t ? i : j];
        S += diff;
        cout << S << "\n";

        arr[t][i][j] = k;
    }

    return 0;
}
