#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll totalCt[26], seen[26];
string s;
ll fact[35];

ll count(ll seen2[], int up) {
    ll left[26];
    for (int i = 0; i < 26; i++) left[i] = totalCt[i] - seen2[i];

    ll b = 1;
    ll sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += left[i];
        b *= fact[left[i]];
    }
    ll a = fact[sum] / b;
    ll ans = 0;
    for (int i = 0; i < up; i++) {
        if (left[i] > 0) {
            ans += a * left[i] / sum;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for (int i = 1; i <= 30; i++) fact[i] = i * fact[i - 1];

    while (cin >> s) {
        if (s == "#") return 0;
        memset(totalCt, 0, sizeof totalCt);
        memset(seen, 0, sizeof seen);
        for (auto c : s) totalCt[c - 'a']++;
        ll ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            ans += count(seen, s[i] - 'a');
            seen[s[i] - 'a']++;
        }
        cout << right << setw(10) << ans + 1 << endl;
    }

    return 0;
}
