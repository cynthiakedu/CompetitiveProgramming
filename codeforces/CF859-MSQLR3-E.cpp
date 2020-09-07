#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 2e5;
int N;
int arr[mxN + 5][2];

vector<ii> adj[mxN + 5];

bool vis[mxN + 5], vis2[mxN + 5], vis3[mxN + 5];

ll num = 0, num2 = 0;
ll ans = 1;
bool hasCycle = false;
int firstInCycle = -1;
bool okEnd = true;

void dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (v.second == 1) {
            num++;
        }
        if (v.first == u) {
            okEnd = false;
        }
        if (vis[v.first]) continue;
        dfs(v.first);
    }
}

void dfs2(int u) {
    vis2[u] = true;
    for (auto v : adj[u]) {
        if (v.second == 0) continue;
        if (vis2[v.first]) {
            hasCycle = true;
            firstInCycle = v.first;
            return;
        }
        dfs2(v.first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        adj[arr[i][0]].push_back({arr[i][1], 1});
        adj[arr[i][1]].push_back({arr[i][0], 0});
    }
    for (int i = 1; i <= 2 * N; i++) {
        if (vis[i]) continue;
        num = 0;
        okEnd = true;
        hasCycle = false;
        dfs(i);
        if (!okEnd) continue;
        dfs2(i);
        num++;

        if (hasCycle) {
            num = 2;
        }

        if (num == 0) continue;
        ans = (ans * (num)) % MOD;
    }

    cout << ans << "\n";

    return 0;
}
