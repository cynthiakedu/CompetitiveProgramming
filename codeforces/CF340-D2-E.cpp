#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int N;
int arr[2005];
int total = 0, part = 0;

ll fact[2005];
ll dp[2005][2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == -1) total++;
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] != -1) continue;
        bool ok = true;
        for (int j = 1; j <= N; j++) {
            if (arr[j] == i) ok = false;
        }
        if (ok) part++;
    }

    fact[0] = 1;
    for (ll i = 1; i <= 2000; i++) fact[i] = (fact[i - 1] * i) % MOD;

    for (int n = 0; n <= 2000; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0) {
                dp[n][k] = fact[n];
                continue;
            }
            dp[n][k] = (dp[n][k - 1] - dp[n - 1][k - 1] + 2 * MOD) % MOD;
        }
    }
    cout << dp[total][part] << endl;

    return 0;
}
