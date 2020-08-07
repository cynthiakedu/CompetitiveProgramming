#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;

int arr[30][30];

bool isValid(int x, int y) {
    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= M) return false;
    if (arr[x][y] == -1) return false;
    return true;
}

vector<pair<ii, int>> getNeigh(ii u) {
    int x = u.first, y = u.second;
    vector<pair<ii, int>> v;
    vector<int> dirx = {-1, 1, 0, 0};
    vector<int> diry = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int a = x + dirx[i], b = y + diry[i];
        if (isValid(a, b)) {
            v.push_back({ii(a, b), arr[a][b]});
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        memset(arr, 0, sizeof arr);

        cin >> M >> N;
        if (N == 0 && M == 0) return 0;
        ii s, e;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char c;
                cin >> c;
                if (c == 'S') {
                    s = {i, j};
                } else if (c == 'D') {
                    e = {i, j};
                } else if (c == 'X') {
                    arr[i][j] = -1;
                } else {
                    arr[i][j] = c - '0';
                }
            }
        }

        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        map<ii, int> dist;

        pq.push({0, s});
        dist[s] = 0;

        while (!pq.empty()) {
            pair<int, ii> front = pq.top();
            pq.pop();
            int d = front.first;
            ii u = front.second;
            if (d > dist[u]) continue;
            for (auto v : getNeigh(u)) {
                if (dist.count(v.first) == 0 || dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        cout << dist[e] << endl;
    }

    return 0;
}
