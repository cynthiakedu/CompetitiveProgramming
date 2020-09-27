#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 5e5 + 5;
ll MOD = 1e9 + 7;
bool debug = false;

int N, in[MXN], out[MXN], numComp[MXN], p[MXN], r[MXN];
vector<int> adj[MXN];
ll dpIn[MXN], dpOut[MXN], f[MXN], ans = 1;

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
    if (findSet(a) == findSet(b)) bad();
    numComp[u]--, unionSet(a, b);
}

void dfs(int u, int par = -1) {
    numComp[u] = (par != -1 ? 1 : 0);
    map<int, int> inM, outM;

    //Collect values
    if (in[u]) inM[in[u]] = u;
    if (out[u]) outM[u] = u;
    for (int v : adj[u]) {
        if (v == par) continue;
        numComp[u]++;
        dfs(v, u);
        if (dpIn[v]) inM[dpIn[v]] = v;
        if (dpOut[v]) outM[dpOut[v]] = v;
    }

    //Check for external in/outs
    for (auto p : inM) {
        if (outM.count(p.first)) continue;
        if (dpIn[u]) bad();
        dpIn[u] = p.first, outM[p.first] = par;
    }
    for (auto p : outM) {
        if (inM.count(p.first)) continue;
        if (dpOut[u]) bad();
        dpOut[u] = p.first, inM[p.first] = par;
    }

    //Union paths
    for (auto p : outM) {
        if (inM[p.first] == u || p.second == u) continue;
        tryUnion(inM[p.first], p.second, u);
    }
    if (in[u] && out[u]) {
        int a = findSet(outM[in[u]]), b = findSet(inM[u]);
        if (a == b && numComp[u] > 1) bad();
        if (a != b) tryUnion(inM[u], outM[in[u]], u);
    }

    //Get answer
    ans = (ans * f[numComp[u] - (in[u] || out[u])]) % MOD;

    if (debug) cout << "dp " << u << " " << f[numComp[u] - (in[u] || out[u])] << endl;
    if (debug) cout << "in/out = " << u << " " << dpIn[u] << " " << dpOut[u] << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    f[0] = 1;
    for (ll i = 1; i < MXN; i++) f[i] = (f[i - 1] * i) % MOD;

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