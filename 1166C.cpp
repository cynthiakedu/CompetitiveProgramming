#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> v;
ll ans = 0;
vector<int> S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        v.push_back(abs(x));
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        ll position = (ll)(lower_bound(S.begin(), S.end(), (x + 1) / 2) - S.begin());
        ans += (ll)S.size() - position;
        S.push_back(x);
    }
    cout << ans << endl;

    return 0;
}
