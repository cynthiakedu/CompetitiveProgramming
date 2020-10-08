#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1500;
int N, M;
int a, b;
char arr[2][mxN + 5][mxN + 5];
bool vis[mxN + 5][mxN + 5];
map<ii, ii> adj;

vector<ii> getNeigh(int x, int y, int idx) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<ii> v;
    for (int i = 0; i < 4; i++) {
        int x0 = (x + dx[i] + N) % N, y0 = y + dy[i];
        if (y0 < 0 || y0 >= N) continue;
        if (arr[idx][x0][y0] == '#') continue;
        v.push_back({x0, y0});
    }
    return v;
}

void dfs(int x, int y, int idx) {
    if (vis[x][y]) return;
    vis[x][y] = true;
    for (auto v : getNeigh(x, y, idx)) {
        dfs(v.first, v.second, idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[0][i][j];
            arr[1][j][i] = arr[0][i][j];
            if (arr[0][i][j] == 'S') {
                a = i;
                b = j;
            }
        }
    }

    dfs(a, b, 0);

    for (int i = 0; i < M; i++) {
    }

    return 0;
}
