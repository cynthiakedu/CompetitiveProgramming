#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, Q, a[200005], k[200005];
vector<ll> acum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    ll c = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        c += a[i];
        acum.push_back(c);
    }

    for (int i = 1; i <= Q; i++) {
        cin >> k[i];
        k[i] += k[i - 1];
    }
    int lst = 0;

    for (int i = 1; i <= Q; i++) {
        ll amt = k[i] - k[lst];
        ll pos = (ll)(upper_bound(acum.begin(), acum.end(), amt) - acum.begin());
        if (pos == acum.size()) {
            lst = i;
            cout << N << endl;
        } else {
            cout << acum.size() - pos << endl;
        }
    }

    return 0;
}
