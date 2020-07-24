#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<ii> fd(int x, int y) {
    vector<ii> v1;
    vector<int> d = {-1, 1};
    for (auto i : d) {
        for (auto j : d) {
            ii a = {x + i, y + 2 * j};
            if (0 <= a.first && a.first < 8 && 0 <= a.second && a.second < 8) {
                v1.push_back(a);
            }
            a = {x + 2 * i, y + j};
            if (0 <= a.first && a.first < 8 && 0 <= a.second && a.second < 8) {
                v1.push_back(a);
            }
        }
    }
    return v1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    while (cin >> s1 && cin >> s2) {
        ii p1 = {s1[0] - 'a', (s1[1] - '1')};
        ii p2 = {s2[0] - 'a', (s2[1] - '1')};

        queue<ii> q;
        map<ii, int> vis;
        q.push(p1);
        vis[p1] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            for (auto v : fd(u.first, u.second)) {
                if (vis.count(v) == 0) {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
        cout << "To get from " << s1 << " to " << s2 << " takes " << vis[p2] << " knight moves." << endl;
    }

    return 0;
}
