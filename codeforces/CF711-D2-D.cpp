#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int N;
set<int> adj[200005];
bool vis[200005];
ll ct = 0;
ll ans = 1;
bool ok;
ll total = 0, used = 0;

void dfs(int x, int p = -1) {
    if (vis[x]) {
        ok = true;
        return;
    };
    vis[x] = true;
    ct++;
    for (auto v : adj[x]) {
        if (v == p) continue;
        dfs(v);
    }
}

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return (((z * z) % MOD) * (b % 2 == 1 ? a : 1)) % MOD;
}
ll getCount(ll ct) {
    return (powmod(2, ct) - 2 + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        adj[i].insert(x);
        adj[x].insert(i);
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        if (adj[i].size() == 1) {
            vis[i] = true;
            vis[*adj[i].begin()] = true;
            ans = (ans * getCount(2)) % MOD;
        } else {
            ct = 0;
            ok = false;
            dfs(i);
            if (ok) {
                ans = (ans * getCount(ct)) % MOD;
            } else {
                ans = (ans * powmod(2, ct - 1)) % MOD;
            }
        }
    }
    cout << (ans % MOD) << endl;
    return 0;
}
