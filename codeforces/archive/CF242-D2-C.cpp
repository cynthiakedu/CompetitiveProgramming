#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
typedef pair<int, int> ii;
int X0, Y0, X1, Y1;
int N;
map<int, vector<ii>> m;
map<int, vector<int>> mx;

bool check(int x, int y) {
    if (x < 1 || x > MAX || y < 1 || y > MAX) return false;
    if (m.count(x) == 0) return false;
    int pos = (int)(upper_bound(m[x].begin(), m[x].end(), ii(y, INT_MAX)) - m[x].begin());
    if (pos == 0 || mx[x][pos - 1] < y) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X0 >> Y0 >> X1 >> Y1;
    cin >> N;
    for (int i = 0, r, a, b; i < N; i++) {
        cin >> r >> a >> b;
        m[r].push_back(ii(a, b));
    }
    for (auto p : m) {
        sort(m[p.first].begin(), m[p.first].end());
    }
    for (auto p : m) {
        for (int i = 0; i < p.second.size(); i++) {
            mx[p.first].push_back(p.second[i].second);
            if (i > 0) mx[p.first][i] = max(mx[p.first][i], mx[p.first][i - 1]);
        }
    }
    queue<ii> q;
    map<ii, int> dist;
    q.push(ii(X0, Y0));
    dist[ii(X0, Y0)] = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int x1 = u.first + i, y1 = u.second + j;
                if (check(x1, y1) && dist.count({x1, y1}) == 0) {
                    dist[ii(x1, y1)] = dist[u] + 1;
                    q.push({x1, y1});
                }
            }
        }
    }
    if (dist.count({X1, Y1}) == 0) {
        cout << -1 << endl;
    } else {
        cout << dist[{X1, Y1}] << endl;
    }

    return 0;
}
