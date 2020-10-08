#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 2005
#define MOD 1000000007
bool debug = false;

int N, D, arr[MXN], currVal, currCtr;
int ctr[MXN], ctrTemp[MXN];
vector<int> adj[MXN];
ll ans;

ll dfs(int u, int p = -1) {
    ll ret = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (arr[v] > currVal + D || arr[v] < currVal) continue;
        if (arr[v] == currVal && currCtr < ctr[v]) continue;  //used ctr[u] instead of currCtr
        ll t = dfs(v, u);
        ret = (ret * (1 + t)) % MOD;
    }
    if (debug) cout << "visit " << u << " " << ret << endl;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> D >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ctr[i] = ++ctrTemp[arr[i]];  //used ctr instead of ctrTemp
    }
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        currVal = arr[i], currCtr = ctr[i];  //forgot this line
        ll tmp = dfs(i);
        ans = (ans + tmp) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
