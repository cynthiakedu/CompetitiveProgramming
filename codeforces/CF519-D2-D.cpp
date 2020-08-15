#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int val[26];
map<ll, ll> m[26];
string s;
ll cum = 0;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 26; i++) cin >> val[i];
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        ans += m[x][cum];
        cum += val[x];
        m[x][cum]++;
    }
    cout << ans << endl;

    return 0;
}
