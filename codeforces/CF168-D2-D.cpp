#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, L, K;

double arr[205];
int bags[205];

double dp[205][205][205][2];

double solve(int i, int j, int a, int b) {
    int a1 = a, b1 = b;
    if (i == 0) {
        if (j >= L && b == 1) {
            return 1.0;
        } else {
            return 0.0;
        }
    }
    double& ret = dp[i][j][a][b];
    if (ret != -1.0) return ret;

    ret = (1.0 - arr[i]) * solve(i - 1, j, a, b);
    int x = bags[i];
    if (bags[i] > 0) {
        if (b == 0) {
            if (a <= x) {
                b = 1;
                a = x - a;
            } else {
                a -= x;
            }
        } else {
            a += x;
        }
    } else {
        if (b == 0) {
            a++;
        } else if (a == 0) {
            b = 0;
            a++;
        } else {
            a--;
        }
    }
    a = min(a, N);
    ret += arr[i] * solve(i - 1, j + 1, a, b);
    // cout << "dp " << i << " " << j << " " << a1 << " " << b1 << " " << ret << endl;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++) {
            for (int a = 0; a < 205; a++) {
                for (int b = 0; b < 2; b++) {
                    dp[i][j][a][b] = -1;
                }
            }
        }
    }

    cin >> N >> L >> K;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        arr[i] = 1.0 * x / 100;
    }
    for (int i = 1; i <= N; i++) {
        cin >> bags[i];
    }
    cout << setprecision(16) << solve(N, 0, min(K, N), 1) << endl;

    return 0;
}
