#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
map<string, vector<pair<string, ii>>> adj;
map<string, ii> vis;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

void dfs(string x) {
    ll a = vis[x].first, b = vis[x].second;

    for (auto p : adj[x]) {
        string p2 = p.first;
        if (vis.count(p2)) continue;
        ll a1 = p.second.first, b1 = p.second.second;
        a1 *= a;
        b1 *= b;
        ll g = gcd(a1, b1);
        a1 /= g;
        b1 /= g;
        vis[p2] = {a1, b1};
        dfs(p2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        char c;
        string s1, s2, e;
        int a, b;
        cin >> c;
        if (c == '.') return 0;
        if (c == '!') {
            cin >> a >> s1 >> e >> b >> s2;
            ll g = gcd(a, b);
            a /= g;
            b /= g;
            adj[s1].push_back({s2, {a, b}});
            adj[s2].push_back({s1, {b, a}});
        } else {
            cin >> s1 >> e >> s2;
            vis.clear();
            vis[s1] = {1, 1};
            dfs(s1);
            if (vis.count(s2) == 0) {
                cout << "? " << s1 << " = ? " << s2 << endl;
            } else {
                cout << vis[s2].first << " " << s1 << " = " << vis[s2].second << " " << s2 << endl;
            }
        }
    }

    return 0;
}