#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string S;
ll N, D;

ll p(ll a, ll b) {
    if (b == 0) return 1;
    ll z = p(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S >> D;
    N = S.size();
    ll ans = 0, ans2 = stoll(S);
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '9')
            ans++;
        else
            break;
    }
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == '0') continue;
        ll need = 1 + stoll(S.substr(i + 1, N - 1 - i)) % (p(10, N - i - 1));
        if (need <= D) {
            if (N - i - 1 > ans) {
                ans = N - i - 1;
                ans2 = stoll(S) - need;
            }
        }
    }
    cout << ans2 << endl;

    return 0;
}
