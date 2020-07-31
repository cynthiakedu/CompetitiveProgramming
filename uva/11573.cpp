#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int R, C, N, arr[1005][1005];
int dist[1005][1005];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int x, int y) {
    if (x < 1 || x > R) return false;
    if (y < 1 || y > C) return false;
    return true;
}

vector<ii> fd(int x, int y) {
    vector<ii> v(8);
    for (int i = 0; i < 8; i++) {
        int x1 = x + dx[i], y1 = y + dx[i];
        v[i] = {x1, y1};
    }
    return v;
}

int bfs(int a, int b, int c, int d) {
    // cout << "bfs " << endl;
    memset(dist, -1, sizeof dist);
    queue<ii> q;
    q.push({a, b});
    dist[a][b] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        cout << "x y " << x << " " << y << endl;
        q.pop();
        vector<ii> v = fd(x, y);
        if (dist[x][y] != -1 && x == c && y == d) {
            cout << "here 1" << endl;
            return dist[x][y];
        }

        for (int i = 0; i < v.size(); i++) {
            int a1 = v[i].first, b1 = v[i].second;
            if (!isValid(a1, b1) || dist[a1][b1] != -1) continue;
            dist[a1][b1] = dist[x][y] + (i == arr[x][y] ? 0 : 1);
            if (a1 == c && b1 == d) {
                cout << "here 2" << endl;
                return dist[a1][b1];
            }
            q.push({a1, b1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << bfs(a, b, c, d) << endl;
    }

    return 0;
}

// 5 5
// 04125
// 03355
// 64734
// 72377
// 02062
// 1
// 4 2 4 2

// 5 5
// 04125
// 03355
// 64734
// 72377
// 02062
// 1
// 4 5 1 4

// 5 5
// 04125
// 03355
// 64734
// 72377
// 02062
// 1
// 3 4 1 4