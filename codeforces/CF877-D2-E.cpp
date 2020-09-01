#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ii pair<ll, ll>
const ll mxN = 2e5;
ll N;
vector<ll> adj[mxN + 5];
ll leaf = 1;
ll intervals[mxN + 5][2];
ll totalNum[mxN + 5];

void dfs(ll u) {
    intervals[u][0] = leaf++;
    totalNum[u] = 1;
    for (ll v : adj[u]) {
        dfs(v);
        totalNum[u] += totalNum[v];
    }
    intervals[u][1] = leaf++;
}

class FenwickTree {
private:
    vector<ll> ft;

public:
    FenwickTree(ll n) { ft.assign(n + 1, 0LL); }
    ll rsq(ll b) {
        ll sum = 0;
        for (; b; b -= (b & (-b))) sum += ft[b];
        return sum;
    }
    ll rsq(ll a, ll b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    void adjust(ll k, ll v) {
        // cout << "adjust " << k << " " << v << endl;
        for (; k < (ll)ft.size(); k += (k & (-k))) {
            // cout << "k " << k << endl;
            ft[k] += v;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (ll i = 2, x; i <= N; i++) {
        cin >> x;
        adj[x].push_back(i);
    }

    FenwickTree f1(3 * N + 5);
    FenwickTree f2(3 * N + 5);
    FenwickTree f3(3 * N + 5);
    dfs(1);
    for (ll i = 1, x; i <= N; i++) {
        cin >> x;
        f2.adjust(intervals[i][0], x);
    }

    ll Q;
    cin >> Q;
    for (ll q = 0; q < Q; q++) {
        string type;
        ll x;
        cin >> type >> x;
        if (type == "get") {
            ll a = f3.rsq(1, intervals[x][0] - 1) % 2;
            ll b = f2.rsq(intervals[x][0], intervals[x][1]);
            ll c = f1.rsq(intervals[x][0], intervals[x][1]);
            if (a) {
                b = totalNum[x] - b;
            }
            b += c;
            cout << b << "\n";
        } else {
            ll a = f3.rsq(1, intervals[x][0] - 1) % 2;
            ll b = f2.rsq(intervals[x][0], intervals[x][1]);
            ll c = f1.rsq(intervals[x][0], intervals[x][1]);
            if (a) {
                b = totalNum[x] - b;
            }
            b += c;
            f1.adjust(intervals[x][0], totalNum[x] - b * 2LL);
            ll d = f3.rsq(intervals[x][0], intervals[x][0]);
            f3.adjust(intervals[x][0], d ? -1 : 1);
            f3.adjust(intervals[x][1], d ? 1 : -1);
        }
    }

    return 0;
}

// 5
// 1 1 2 2
// 0 0 0 0 0
// 4
// get 2
// pow 2
// pow 2
// get 5

// 4
// 1 2 3
// 0 0 0 1
// 8
// pow 3
// pow 1
// pow 2
// pow 4
// get 1
// get 2
// get 3
// get 4