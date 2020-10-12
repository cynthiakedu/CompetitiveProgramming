#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 5;
int n, m, s2[MXN];
uint64_t s1[MXN], ans, s[MXN];
map<uint64_t, int64_t > mp1, mp2;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> dst(0, ULLONG_MAX);

    cin >> n >> m;
    for (int i = 1, l, r; i <= n; ++i) {
        cin >> l >> r;
        uint64_t tmp = dst(rng);
        s[l] ^= tmp, s[r] ^= tmp;
        s2[l]++, s2[r + 1]--;
    }

    for (int i = 1; i <= m + 1; ++i) {
        s2[i] += s2[i - 1], s[i] ^= s[i - 1];
        s1[i + 1] = s1[i] ^ s[i];
    }

    for (int i = 1; i <= m; ++i) {
        ++mp1[s1[i]], mp2[s1[i]] += i - 1;
        ans -= 1LL * mp2[s1[i]];
        ans += 1LL * mp1[s1[i]] * i;
    }

    int l = 0;
    for (int i = 1; i <= m + 1; ++i) {
        if (i == m + 1 || s2[i]) {
            for (int j = 1; j <= l; ++j) {
                ans -= 1LL * j * (l - j + 1);
            }
            l = 0;
        } else ++l;
    }
    cout << ans << "\n";

}

