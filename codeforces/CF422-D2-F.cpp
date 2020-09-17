#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 105
bool debug = false;

int N, childCt[MXN], edge[MXN];
vector<ii> adj[MXN];
int ans = 0, ans2[MXN][3];
double ans3[MXN];

double m2(double x) {
    while (x >= 2) x -= 2;
    return x;
}

void dfs(int u, double x, int p = -1) {
    if (debug) cout << "visit " << u << " " << x << endl;
    for (auto v : adj[u]) childCt[u]++;

    double add = 2.0 / childCt[u], curr = x;  //bug: had curr = 0.0

    if (debug) cout << "add " << add << " " << curr << endl;

    for (auto v : adj[u]) {
        if (v.first == p) continue;
        curr = m2(curr + add);
        ans++;
        ans2[ans][0] = v.second, ans2[ans][1] = v.first, ans2[ans][2] = u;
        ans3[ans] = curr;
        if (debug) cout << "child " << v.first << " " << ans3[ans] << endl;
        if (ans3[ans] >= 1) {
            ans3[ans] -= 1;
            swap(ans2[ans][1], ans2[ans][2]);
        }
        dfs(v.first, m2(curr + 1), u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1, u, v; i <= N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    dfs(1, 0.0);

    cout << N - 1 << "\n";
    for (int i = 1; i <= ans; i++) {
        cout << 1 << " " << ans2[i][0] << " " << ans2[i][1] << " " << ans2[i][2] << " ";
        cout << setprecision(16) << ans3[i] << "\n";
    }

    return 0;
}
