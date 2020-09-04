#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, int>
const int mxN = 1e6;
int N, M;
ll K;
vector<pair<ll, pair<int, int>>> v;
bool mark[1005][1005];
ll ans[1005][1005];
ll need, paintNum, ct;
int p[mxN + 5], r[mxN + 5];
ll num[mxN + 5];

int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        if (r[x] < r[y]) {
            p[x] = y;
            num[y] += num[x];
        } else {
            p[y] = x;
            num[x] += num[y];
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
}

bool isValid(int x, int y) {
    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= M) return false;
    return mark[x][y];
}

vector<ii> getNeigh(int x, int y) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<ii> ret;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i], y1 = y + dy[i];
        if (isValid(x1, y1)) {
            ret.push_back({x1, y1});
        }
    }
    return ret;
}

void bfs(int x, int y) {
    if (ct == need) return;
    ans[x][y] = paintNum;
    ct++;
    for (auto v : getNeigh(x, y)) {
        if (ct == need) return;
        if (!ans[v.first][v.second]) {
            bfs(v.first, v.second);
        }
    }
}

int getNewCoord(int x, int y) {
    return x * M + y;
}

bool solve() {
    int idx = 0;
    while (idx < (int)v.size()) {
        paintNum = v[idx].first;
        int j = idx;
        if (K % paintNum == 0) {
            need = K / paintNum;
        } else {
            need = LLONG_MAX;
        }
        while (j < (int)v.size() && v[idx].first == v[j].first) {
            int x1 = v[j].second.first, y1 = v[j].second.second;
            int nc = getNewCoord(x1, y1);
            for (auto v : getNeigh(x1, y1)) {
                int nc2 = getNewCoord(v.first, v.second);
                unionSet(nc2, nc);
            }
            mark[x1][y1] = true;
            int rt = findSet(nc);
            if (num[rt] >= need) {
                bfs(x1, y1);
                return true;
            }
            j++;
        }
        idx = j;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N * M; i++) {
        p[i] = i;
        num[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll x;
            cin >> x;
            v.push_back({x, {i, j}});
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    bool ok = solve();
    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << (j == M - 1 ? "\n" : " ");
        }
    }

    return 0;
}
