#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll arr[205], N, K;
int ct2[205], ct5[205];
int dp[205][205][85][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        while (arr[i] % 2 == 0) {
            ct2[i]++;
            arr[i] /= 2;
        }
        while (arr[i] % 5 == 0) {
            ct5[i]++;
            arr[i] /= 5;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= 85; k++) {
                for (int s = 0; s <= 1; s++) {
                    int a = ct2[i], b = ct5[i];
                    //not select
                    int& ret = dp[i][j][k][s];
                    ret = dp[i - 1][j][k][s];

                    int c2 = a + (s == 1 ? k : 0);
                    int c5 = b + (s == 1 ? 0 : k);

                    int amt = min(c2, c5);
                    c2 -= amt;
                    c5 -= amt;
                    int k1, s1;
                    if (c2 >= 0) {
                        k1 = c2;
                        s1 = 1;
                    } else {
                        k1 = c5;
                        s1 = 0;
                    }
                    ret = max(ret, dp[i - 1][j - 1][k1][s1]);
                }
            }
        }
    }
    cout << dp[N][K][0][0] << endl;

    return 0;
}
