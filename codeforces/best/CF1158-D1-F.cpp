#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 3005;
ll MOD = 998244353;
bool debug = false;
const int t1 = 11;
const int t = (1 << t1) + 5;

int N, C, arr[MXN];
int d[MXN][MXN], e[MXN], cd[MXN];
int dp1[MXN][t], dp2[MXN][MXN], ans[MXN];

ll inv(ll a, ll b) {
    return a > 1 ? b - inv(b % a, a) * b / a : 1;
}

ll powmod(ll a, ll b) {
    ll ret = 1;
    for (; b;b >>= 1, a = a * a % MOD) {
        if (b & 1)  ret = ret * a % MOD;
    }
    return ret;
}

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}


void solve1() {
    int a = (1 << C), num, y;
    dp1[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        num = arr[i] - 1, y = i / C;
        for (int j = y; j >= 0; --j) {
            for (int k = 0; k < a - 1; ++k) {
                if (!(k & (1 << num))) continue;
                dp1[j][k] = add(2 * dp1[j][k] % MOD, dp1[j][k ^ (1 << num)]);
            }
            dp1[j + 1][0] = add(dp1[j + 1][0], dp1[j][(a - 1) ^ (1 << num)]);
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int k = 0; k < t; ++k) {
            ans[i] = add(ans[i], dp1[i][k]);
        }
        if (i == 0) ans[i] = (ans[i] - 1 + MOD) % MOD;
        cout << ans[i] << (i == N ? "\n" : " ");
    }
}

void solve2() {
    memset(ans, 0, sizeof ans);

    // d[i][j] = # subsequences in arr[i...j] that contains all 1...C
    // where only last element of the subsequence can be arr[j]
    for (int i = 1, ct = 0; i <= N; ++i, ct = 0) { //TODO CHANGE
        vector<int> v(C + 1, 0); // count of each number
        ll res = 1;
        for (int j = i; j >= 1; --j) {
            int& s = v[arr[j]];
            ct += (s ? 0 : 1);

            if (arr[j] != arr[i]) {
                if (s) res = res * inv((powmod(2, s) - 1 + MOD) % MOD, MOD) % MOD;
                res = res * (powmod(2, s + 1) - 1 + MOD) % MOD;
            }
            s++;

            d[i][j] = (ct == C ? res : 0);
            if (ct == C && !cd[i]) cd[i] = j;
            // cout << "dRes " << i << " " << j << " " << d[i][j] << "\n";
        }
    }

    // e[i] = # subsequences in range[i, N] not containing all 1...C
    e[N + 1] = 1;
    for (int i = N, ct = 0, x; i >= 1; --i) {
        if (arr[i] == arr[N]) { ct++; x = powmod(2, ct); }
        e[i] = (powmod(2, N - i + 1) - d[N][i] * (x - 1 + MOD) % MOD + MOD) % MOD;
        // cout << "e " << i << " " << e[i] << "\n";
    }

    dp2[0][0] = 1;
    int mxP = N / C;
    ll tmp = 0;
    for (int i = 1; i <= mxP; ++i) {
        for (int j = i * C; j <= N; ++j) {
            for (int k = (i - 1) * C; k < cd[j]; ++k) {
                dp2[i][j] = add(dp2[i][j], (ll)dp2[i - 1][k] * (ll)d[j][k + 1] % MOD);
            }
            ans[i] = add(ans[i], ((ll)dp2[i][j] * (ll)e[j + 1]) % MOD);
        }
        tmp = add(tmp, ans[i]);
    }

    ans[0] = (powmod(2, N) - 1 - tmp + 2 * MOD) % MOD;
    for (int i = 0; i <= N; ++i)  cout << ans[i] << (i == N ? "\n" : " ");

}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    // freopen("output.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);

    cin >> N >> C;
    for (int i = 1; i <= N; ++i) cin >> arr[i];

    if (C <= t1)  solve1(); else solve2();
    // solve1();
    // solve2();

    return 0;
}
