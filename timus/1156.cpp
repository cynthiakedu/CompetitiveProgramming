#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
vector<int> adj[200];
int arr[200];
bool ok = true;
vector<int> ans[2];
int ct = 0;
vector<int> amt[200][2];
int choice[200];
vector<int> finalAns[2];

bool dp1[205][105];
int dp2[205][205];

bool dfs(int u, int color = 1, int p = -1) {
    if (arr[u] != -1 && arr[u] != color) {
        return false;
    }
    arr[u] = color;
    amt[ct][color].push_back(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        bool x = dfs(v, 1 - color, u);
        if (!x) return false;
    }
    return true;
}

bool solve(int idx, int num) {
    if (num > N) return false;
    if (idx == ct) {
        return num == N;
    }

    choice[idx] = 0;
    bool ok1 = solve(idx + 1, num + amt[idx][0].size());
    if (ok1) return true;
    choice[idx] = 1;
    bool ok2 = solve(idx + 1, num + amt[idx][1].size());
    if (ok2) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(arr, -1, sizeof arr);
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= 2 * N; i++) {
        if (arr[i] != -1) continue;
        ct++;
        bool x = dfs(i);
        if (!x) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = ct + 1; i >= 1; i--) {
        // cout << "start dp " << i << " " << amt[i][0].size() << " " << amt[i][1].size() << endl;
        for (int j = 0; j <= N; j++) {
            if (i == ct + 1) {
                dp1[i][j] = (j == 0);
                continue;
            }
            dp1[i][j] = false;
            for (int k = 0; k < 2; k++) {
                if (j >= amt[i][k].size() && dp1[i + 1][j - amt[i][k].size()]) {
                    dp1[i][j] = true;
                    dp2[i][j] = k;
                }
            }
            // cout << "dp " << i << " " << j << " " << dp1[i][j] << endl;
        }
    }

    if (dp1[1][N] == false) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int x = N;
    for (int i = 1; i <= ct; i++) {
        int c = dp2[i][x];
        x -= amt[i][c].size();
        for (auto x : amt[i][c]) {
            finalAns[0].push_back(x);
        }
        for (auto x : amt[i][1 - c]) {
            finalAns[1].push_back(x);
        }
    }
    for (int i = 0; i < 2; i++) {
        int n = finalAns[i].size();
        for (int j = 0; j < n; j++) {
            cout << finalAns[i][j] << (j == n - 1 ? "\n" : " ");
        }
    }

    return 0;
}
