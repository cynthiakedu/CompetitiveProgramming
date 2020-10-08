#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
long double p, k;
long double intervals[5005][2];
long double ans[5005];

long double powmod(long double a, ll b) {
    if (b == 0) return 1;
    long double z = powmod(a, b / 2);
    return z * z * ((long long)b % 2 ? a : (long double)1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> k;
    bool ok = (((ll)p) % 2 == 1) && ((ll)k % 2 == 0);
    intervals[0][0] = 0;
    intervals[0][1] = k - 1;
    int i = 0;
    while (true) {
        if (p > 0 && intervals[i][1] >= p) {
            break;
        }
        if (p < 0 && intervals[i][0] <= p) {
            break;
        }
        i++;
        if (i % 2 == 0) {
            intervals[i][0] = intervals[i - 1][0];
            intervals[i][1] = intervals[i - 1][1] + (k - 1) * powmod(k, i);
        } else {
            intervals[i][1] = intervals[i - 1][1];
            intervals[i][0] = intervals[i - 1][0] - (k - 1) * powmod(k, i);
        }
    }

    for (int j = i; j >= 1; j--) {
        long double x = powmod(k, (ll)j);
        if (j % 2) x = -x;
        for (int s = k - 1; s >= 1; s--) {
            if (p - s * x >= intervals[j - 1][0] && p - s * x <= intervals[j - 1][1]) {
                if (j == 1) {
                    p -= (ll)s * (ll)x;
                } else {
                    p -= s * x;
                }
                ans[j] = s;
                break;
            }
        }
    }
    ans[0] = p;
    if (ok && ((ll)ans[0]) % 2 == 0) ans[0]++;

    cout << i + 1 << endl;
    for (int x = 0; x <= i; x++) cout << ans[x] << (x == i ? "\n" : " ");
    long double num = 0;
    for (int x = 0; x <= i; x++) {
        num += ans[x] * powmod(k, x) * (x % 2 == 1 ? -1 : 1);
    }
    return 0;
}
