#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int r1, c1, r2, c2;
int N, M;
char arr[505][505];

bool isValid(int x, int y) {
    if (x <= 0 || x > N) return false;
    if (y <= 0 || y > M) return false;
    return true;
}

vector<ii> getNeigh(int x, int y) {
    vector<ii> v;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int x0 = x + dx[i], y0 = y + dy[i];
        v.push_back({x0, y0});
    }
    return v;
}

bool solve() {
    queue<ii> q;
    q.push({r1, c1});
    map<ii, int> dist;
    dist[{r1, c1}] = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        arr[u.first][u.second] = 'X';
        for (auto v : getNeigh(u.first, u.second)) {
            if (v.first == r2 && v.second == c2) {
                if (arr[r2][c2] == 'X') return true;
                for (auto v1 : getNeigh(r2, c2)) {
                    if (arr[v1.first][v1.second] == '.') return true;
                }
                return false;
            }
            if (dist.count(v) == 0 && arr[v.first][v.second] == '.') {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return false;
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
    cin >> r1 >> c1 >> r2 >> c2;

    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
