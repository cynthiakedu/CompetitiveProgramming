#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p(ll a, ll b) {
    if (b == 0) return 1;
    ll z = p(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line1, line2;

    while ((getline(cin, line1)) && getline(cin, line2)) {
        istringstream sline1(line1), sline2(line2);
        ll x;
        vector<ll> poly, nums;
        while (sline1 >> x) {
            poly.push_back(x);
        }
        while (sline2 >> x) {
            nums.push_back(x);
        }
        for (int i = 0; i < nums.size(); i++) {
            ll ans = 0;
            for (int j = 0; j < poly.size(); j++) {
                int d = poly.size() - 1 - j;
                ll res = poly[j] * p(nums[i], d);
                ans += res;
            }
            cout << ans << (i == nums.size() - 1 ? "\n" : " ");
        }
    }
    return 0;
}
