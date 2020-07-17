#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
map<int, ll> a;
map<int, ll> b;
ll ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int l = 0, r = 0;
        for (auto c : s) {
            if (c == '(') {
                l++;
            } else {
                if (l > 0)
                    l--;
                else
                    r++;
            }
        }
        if (l == 0 && r == 0) {
            a[0]++;
            b[0]++;
        } else if (l == 0) {
            b[r]++;
        } else if (r == 0) {
            a[l]++;
        }
    }
    for (auto p : a) {
        ans += p.second * b[p.first];
    }
    cout << ans << endl;

    return 0;
}
