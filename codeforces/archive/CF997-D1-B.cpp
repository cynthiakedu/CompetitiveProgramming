#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int mn[500];
ll ct[500];
ll N;
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // set<int> S;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         for (int k = 0; k <= N; k++) {
    //             if (i + j + k <= N) {
    //                 S.insert(49 * i + 4 * j + 9 * k);
    //             }
    //         }
    //     }
    // }
    // cout << "SIZE " << S.size() << endl;
    for (int i = 0; i < 140; i++) mn[i] = INT_MAX;
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            int x = i * 9 + j * 4;
            if (x < 100) {
                mn[x] = min(mn[x], i + j);
            }
        }
    }
    for (int i = 0; i < 49; i++) {
        if (mn[i] == INT_MAX) {
            mn[i] = mn[i + 49];
        }
    }

    for (int a = 0; a <= 30; a++) {
        for (int i = 0; i < 49; i++) {
            if (mn[i] <= a) ct[a]++;
        }
    }
    ll N2 = min(N, 30LL);
    ll N1 = N - N2;
    for (ll i = 0; i <= N2; i++) {
        ans += ct[i];
    }
    if (N1 > 0) {
        ans += N1 * ct[30];
    }

    cout << ans << endl;

    return 0;
}
