#include <bits/stdc++.h>
using namespace std;
int T, N, M;
char arr[10][10];
int p[100], vis[100];  //CLEAR every time
set<char> S = {'I', 'E', 'H', 'O', 'V', 'A', '#'};

void dfs(int node, int par = -1) {
    int x = node / M;
    int y = node - x * M;
    if (x < 0 || x >= N) return;
    if (y < 0 || y >= M) return;
    if (vis[node]) return;
    p[node] = par;
    vis[node] = true;

    if (S.count(arr[x][y]) == 0) return;

    dfs(node + M, node);
    dfs(node - 1, node);
    dfs(node + 1, node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        memset(arr, ' ', sizeof arr);
        memset(p, -1, sizeof p);
        memset(vis, false, sizeof vis);

        int s, e;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    s = M * i + j;
                }
                if (arr[i][j] == '#') {
                    e = M * i + j;
                }
            }
        }
        dfs(e);
        vector<string> ans;
        while (s != e) {
            int n = p[s];
            if (n == s - M) {
                ans.push_back("forth");
            } else if (n == s + 1)
                ans.push_back("right");
            else
                ans.push_back("left");
            s = n;
        }
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

    return 0;
}