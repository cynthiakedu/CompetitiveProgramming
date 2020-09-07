#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 1e6;
int N;
string a, b;
int ctA[26], ctB[26];

ll fact[mxN + 5];
ll invMemo[mxN + 5];
ll multicopy = 1;

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
ll solve(string x) {
    int ctLeft[26] = {};
    for (char c : a) ctLeft[c - 'a']++;

    ll mult = multicopy;

    ll ret = 0;

    for (int i = 0; i < N; i++) {
        int c = x[i] - 'a';
        mult = (mult * inv(N - i, MOD)) % MOD;
        for (int j = 0; j < c; j++) {
            if (ctLeft[j] == 0) continue;
            ret = (ret + (mult * ctLeft[j]) % MOD) % MOD;
        }
        if (ctLeft[c] == 0) break;
        mult = (mult * ctLeft[c]) % MOD;
        ctLeft[c]--;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (ll i = 1; i < mxN + 5; i++) fact[i] = (fact[i - 1] * i) % MOD;

    cin >> a >> b;
    N = a.size();

    int ctLeft[26] = {};
    for (char c : a) ctLeft[c - 'a']++;

    multicopy = fact[N];
    for (int i = 0; i < 26; i++) multicopy = (multicopy * (inv(fact[ctLeft[i]], MOD))) % MOD;

    for (char c : a) ctA[c - 'a']++;
    for (char c : b) ctB[c - 'a']++;

    ll numA = solve(a), numB = solve(b);
    ll ans = (numB - numA + MOD) % MOD;
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;

    return 0;
}
