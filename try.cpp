#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 5e5;
ll MOD = 1e9 + 7;
bool debug = false;

int in[MXN], out[MXN], N;
vector<int> adj[MXN];
ll dp[MXN], dpIn[MXN], dpOut[MXN], f[MXN], ans;
int numComp[MXN], inCycle[MXN];
int p[MXN], r[MXN];

void prepare() {
    f[0] = 1;
    for (ll i = 1; i < MXN; i++) f[i] = (f[i - 1] * i) % MOD;
}

void bad() {
    cout << 0 << endl;
    exit(0);
}

int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x == y) return;
    if (r[x] < r[y])
        p[x] = y;
    else {
        p[y] = x;
        if (r[y] == r[x]) r[x]++;
    }
}

void tryUnion(int a, int b, int u) {
    if (debug) cout << "union " << a << " " << b << endl;
    int a1 = findSet(a), b1 = findSet(b), c = findSet(u);
    if (a1 == b1 && a1 != c) bad();
    if (a1 == b1 && a1 == c) inCycle[u] = 1;
    if (a1 != b1) numComp[u]--, unionSet(a1, b1);
}

void dfs(int u, int p = -1) {
    dp[u] = 1, numComp[u] = 1;
    map<int, int> inM, outM;

    //Collect values
    if (in[u]) inM[in[u]] = u;
    if (out[u]) outM[u] = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        numComp[u]++;
        dfs(v, u);
        if (dpIn[v]) inM[dpIn[v]] = v;
        if (dpOut[v]) outM[dpOut[v]] = v;
        dp[u] = (dp[u] * dp[v]) % MOD;
    }

    //Check for external in/outs
    for (auto p : inM) {
        if (outM.count(p.first)) continue;
        if (dpIn[u]) bad();
        dpIn[u] = p.first;
    }
    for (auto p : outM) {
        if (inM.count(p.first)) continue;
        if (dpOut[u]) bad();
        dpOut[u] = p.first;
    }

    //Union paths
    for (auto p : outM) {
        if (!inM.count(p.first)) continue;
        tryUnion(inM[p.first], p.second, u);
    }
    if (dpIn[u] && dpOut[u]) tryUnion(inM[dpIn[u]], outM[dpOut[u]], u);
    if (inCycle[u] && numComp[u] > 1) bad();
    if (inCycle[u] && u != 1 && !(dpIn[u] || dpOut[u])) bad();

    //Get answer
    dp[u] = (dp[u] * f[numComp[u] - 1]) % MOD;
    if (u == 1) ans = dp[u];
    if (!dpIn[u] && !dpOut[u]) dp[u] = (dp[u] * (numComp[u])) % MOD;
    if (debug) cout << "dp " << u << " " << dp[u] << endl;
    if (debug) cout << "in/out = " << u << " " << dpIn[u] << " " << dpOut[u] << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    prepare();

    cin >> N;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        cin >> in[i];
        if (in[i] == i) bad();
        out[in[i]] = i;
    }

    dfs(1);
    cout << ans << "\n";

    return 0;
}