#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[45][45];
int T;
int N, M, B, C;
map<int, ii> boxMap;
map<int, ii> destMap;

bool isValid(ii u) {
    if (u.first <= 0 || u.first > N) return false;
    if (u.second <= 0 || u.second > M) return false;
    if (arr[u.first][u.second] > 0) return false;
    return true;
}

vector<ii> getNeighbors(ii u) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<ii> ret;
    for (int i = 0; i < 4; i++) {
        ii v = {u.first + dx[i], u.second + dy[i]};
        if (isValid(v)) {
            ret.push_back(v);
        }
    }
    return ret;
}

int getDist(ii b, ii d) {
    queue<ii> q;
    map<ii, int> dist;
    q.push(b);
    dist[b] = 0;
    while (!q.empty()) {
        ii u = q.front();
        for (auto v : getNeighbors(u)) {
            if (dist.count(v) == 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return (dist.count(d) > 0 ? dist[d] : -1);
}

int solve(int x) {
    int ct = 0;
    for (int i = B - 1; i >= 0; i--) {
        if (x & (1 << i)) ct++;
    }
    int boxNum = B + 1 - ct;
    if (boxNum == B + 1) return 0;
    int ans = INT_MAX;
    for (int i = B - 1; i >= 0; i--) {
        if (x & (1 << i)) {
            ii b = boxMap[boxNum];
            ii d = destMap[i + 1];
            int dist = getDist(b, d);
            if (dist != -1) {
                arr[b.first][b.second] = 0;
                arr[d.first][d.second] = 16;
                ans = min(ans, dist + solve(x ^ (1 << i)));
                arr[b.first][b.second] = boxNum;
                arr[d.first][d.second] = -(i + 1);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        B = 0;
        C = 0;
        boxMap.clear();
        destMap.clear();
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                char c;
                cin >> c;
                if (c == '#') arr[i][j] = 16;
                if (c == '.') arr[i][j] = 0;
                if (c == 'B') {
                    B++;
                    arr[i][j] = B;
                    boxMap[B] = {i, j};
                }
                if (c == 'C') {
                    c++;
                    arr[i][j] = C;
                    destMap[C] = {i, j};
                }
            }
        }
        cout << solve((1 << 15) - 1) << endl;
    }

    return 0;
}
