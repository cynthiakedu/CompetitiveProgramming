#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define p2 pair<pair<int, ii>, ii>
int N, M, K;
char arr[1005][1005];
int a, b, a1, b1;
vector<ii> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dist[1005][1005], dist2[1005][1005][4];

bool isValid(int x, int y) {
    if (x < 1 || x > N) return false;
    if (y < 1 || y > M) return false;
    if (arr[x][y] == '#') return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof dist);
    memset(dist2, -1, sizeof dist2);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> a >> b >> a1 >> b1;

    priority_queue<p2, vector<p2>, greater<p2>> pq;
    dist[a][b] = 0;
    pq.push({{0, {-1, 0}}, {a, b}});

    while (!pq.empty()) {
        p2 s = pq.top();
        pq.pop();
        int x = s.second.first, y = s.second.second;
        int d = s.first.first;
        ii dir = s.first.second;

        if (dist[x][y] < d) continue;
        if (dir.first != -1 && dist2[x][y][dir.first] < dir.second) continue;
        if (x == a1 && y == b1) break;
        for (int i = 0; i < 4; i++) {
            int x0 = x + v[i].first, y0 = y + v[i].second;
            if (!isValid(x0, y0)) continue;
            int newCost = d + ((dir.first != i || dir.second == K) ? 1 : 0);
            int newLen = (dir.first != i || dir.second == K) ? 1 : dir.second + 1;
            if (dist[x0][y0] == -1 || dist[x0][y0] > newCost) {
                dist[x0][y0] = newCost;
                dist2[x0][y0][i] = newLen;
                pq.push({{dist[x0][y0], {i, newLen}}, {x0, y0}});
            } else if (dist[x0][y0] == newCost) {
                if (dist2[x0][y0][i] == -1 || dist2[x0][y0][i] > newLen) {
                    dist2[x0][y0][i] = newLen;
                    pq.push({{dist[x0][y0], {i, newLen}}, {x0, y0}});
                }
            }
        }
    }
    cout << dist[a1][b1] << endl;

    return 0;
}
