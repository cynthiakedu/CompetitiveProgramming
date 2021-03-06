#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 3005;
ll MOD = 998244353;
bool debug = false;
const int t1 = 10;
const int t = (1 << t1) + 5;

int N, C, arr[MXN];
int d[MXN][MXN], e[MXN], cd[MXN];
int dp1[MXN][t], dp2[MXN][MXN], ans[MXN];

int Pow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = (ll)a * a % MOD) {
        if (b & 1)  ret = (ll)ret * a % MOD;
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
    dp1[0][0] = 1;

    for (int i = 1, num, y; i <= N; ++i) {
        num = arr[i] - 1, y = i / C;
        for (int j = y; j >= 0; --j) {
            for (int k = 0; k < (1 << C) - 1; ++k) {
                if (!(k & (1 << num))) continue;
                dp1[j][k] = add(2 * dp1[j][k] % MOD, dp1[j][k ^ (1 << num)]);
            }
            dp1[j + 1][0] = add(dp1[j + 1][0], dp1[j][((1 << C) - 1) ^ (1 << num)]);
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

    vector<int>pw(N + 1);
    pw[1] = 1;
    for (int i = 2;i <= N;++i) {
        pw[i] = (pw[i - 1] * 2 + 1) % MOD;
    }

    vector<int>inv(N + 1);
    for (int i = 1;i <= N;++i) {
        inv[i] = Pow(pw[i], MOD - 2);
    }

    // d[i][j] = # subsequences in arr[i...j] that contains all 1...C
    // where only last element of the subsequence can be arr[j]
    for (int i = 1, ct = 0; i <= N; ++i, ct = 0) {
        vector<int> v(C + 1, 0); // count of each number
        ll res = 1;
        for (int j = i; j >= 1; --j) {
            int& s = v[arr[j]];
            ct += (s ? 0 : 1);

            if (arr[j] != arr[i]) {
                if (s) res = res * inv[s] % MOD;
                res = res * pw[s + 1] % MOD;
            }
            s++;

            d[i][j] = (ct == C ? res : 0);
            if (ct == C && !cd[i]) cd[i] = j;
        }
    }

    // e[i] = # subsequences in range[i, N] not containing all 1...C
    e[N + 1] = 1;
    for (int i = N, x = 0; i >= 1; --i) {
        if (arr[i] == arr[N]) x++;
        e[i] = (Pow(2, N - i + 1) - (ll)d[N][i] * pw[x] % MOD + MOD) % MOD;
    }

    dp2[0][0] = 1;
    int mxP = N / C;
    ll tmp = 0;
    for (int i = 1; i <= mxP; ++i) {
        for (int j = i * C; j <= N; ++j) {
            for (int k = (i - 1) * C; k < cd[j]; ++k) {
                dp2[i][j] = add(dp2[i][j], (ll)dp2[i - 1][k] * d[j][k + 1] % MOD);
            }
            ans[i] = add(ans[i], ((ll)dp2[i][j] * e[j + 1]) % MOD);
        }
        tmp = add(tmp, ans[i]);
    }

    ans[0] = add(pw[N] - tmp, MOD);
    for (int i = 0; i <= N; ++i)  cout << ans[i] << (i == N ? "\n" : " ");

}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    // int s = clock();
    // freopen("output.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);

    cin >> N >> C;
    for (int i = 1; i <= N; ++i) cin >> arr[i];

    if (C <= t1)  solve1(); else solve2();
    // solve1();
    // solve2();
    // fprintf(stderr, "time: %.3lf s\n", (double)(clock() - s) / CLOCKS_PER_SEC);
    return 0;
}
