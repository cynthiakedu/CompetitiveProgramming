#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 998244353
int N, M;
string s1, s2;
ll cum[200005];

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '1') {
            cum[i] = powmod(2, i);
        }
        cum[i] += cum[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '1') {
            ans = (ans + cum[min(i, (int)s1.size() - 1)]) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
