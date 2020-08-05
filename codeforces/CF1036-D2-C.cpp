#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
string L, R;
ll binom[20][20];

ll bin(ll n, ll k) {
    if (k > n || n <= 0) return 0;
    return binom[n][k];
}

ll ct(string s) {
    if (s == "0") return 0;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') v.push_back(i);
    }
    ll ans = 0;
    ll n = s.size() - 1 - v[0];
    ans += bin(n, 3) * 9 * 9 * 9 + bin(n, 2) * 81 + (n)*9;
    ans += ((s[v[0]] - '0') - 1) * (bin(n, 2) * 81 + (n)*9 + 1);
    if (v.size() > 1) {
        n = s.size() - 1 - v[1];
        ans += bin(n, 2) * 81 + (n)*9 + 1;
        ans += ((s[v[1]] - '0') - 1) * (9 * n + 1);
    }
    if (v.size() > 2) {
        n = s.size() - 1 - v[2];
        ans += 9 * (n) + 1;
        ans += ((s[v[2]] - '0') - 1) * 1;
    }
    return ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n = 1; n < 20; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 || k == n) {
                binom[n][k] = 1;
            } else {
                binom[n][k] = binom[n - 1][k - 1] + binom[n - 1][k];
            }
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        cout << ct(R) - ct(to_string(stoll(L) - 1)) << endl;
    }

    return 0;
}
