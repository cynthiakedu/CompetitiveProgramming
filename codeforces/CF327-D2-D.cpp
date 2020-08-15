#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
char arr[505][505];
bool vis[505][505];
vector<pair<char, ii>> ans;

vector<ii> getNeigh(ii u) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<ii> v;
    for (int i = 0; i < 4; i++) {
        int x = u.first + dx[i], y = u.second + dy[i];
        if (x < 1 || x > N) continue;
        if (y < 1 || y > M) continue;
        if (arr[x][y] == '#') continue;
        v.push_back({x, y});
    }
    return v;
}

void dfs(ii u, bool isRoot) {
    if (vis[u.first][u.second]) return;
    vis[u.first][u.second] = true;
    ans.push_back({'B', ii(u.first, u.second)});
    for (auto v : getNeigh(u)) {
        if (!vis[v.first][v.second]) {
            dfs(v, false);
        }
    }
    if (!isRoot) {
        ans.push_back({'D', ii(u.first, u.second)});
        ans.push_back({'R', ii(u.first, u.second)});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!vis[i][j] && arr[i][j] != '#') {
                dfs({i, j}, true);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
    }
    return 0;
}
