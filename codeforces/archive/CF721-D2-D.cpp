#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
const int mxN = 2e5;
bool sgn[mxN + 5];
int N;
ll K, X;
int oddCt;
ll ans[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> X;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        pq.push({abs(x), i});
        if (x < 0) oddCt++;
        sgn[i] = (x < 0);
    }

    if (oddCt % 2 == 0) {
        ll x = pq.top().first;
        ll id = pq.top().second;
        pq.pop();
        ll need = (x + X - 1) / X;
        ll mn = min(need, K);
        x -= mn * X;
        K -= mn;
        if (x >= 0 && K > 0) {
            K--;
            x -= X;
        }
        if (x < 0) {
            sgn[id] = !sgn[id];
            oddCt++;
        }
        pq.push({abs(x), id});
    }
    if (oddCt % 2 == 1) {
        while (K > 0) {
            pair<ll, ll> p = pq.top();
            pq.pop();
            pq.push({p.first + X, p.second});
            K--;
        }
    }
    while (!pq.empty()) {
        pair<ll, ll> p = pq.top();
        pq.pop();
        ans[p.second] = p.first;
        if (sgn[p.second]) ans[p.second] *= -1;
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
