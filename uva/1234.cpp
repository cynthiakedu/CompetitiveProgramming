#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N, M;
vector<pair<int, ii>> E;
int p[10005], r[10005];

int findSet(int x) { return (p[x] == x ? x : p[x] = findSet(p[x])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) r[x]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        int ans = 0, total = 0;
        for (int i = 0; i < 10005; i++) {
            p[i] = i;
            r[i] = 0;
        }
        E.clear();
        cin >> N >> M;
        for (int i = 0, u, v, c; i < M; i++) {
            cin >> u >> v >> c;
            E.push_back({c, {u, v}});
        }
        sort(E.begin(), E.end());
        reverse(E.begin(), E.end());
        for (auto p : E) {
            int c = p.first;
            total += c;
            int u = p.second.first, v = p.second.second;
            if (!isSameSet(u, v)) {
                unionSet(u, v);
                ans += c;
            }
        }
        cout << total - ans << endl;
    }

    return 0;
}
// 2
// 6 7
// 1 2 5
// 2 3 3
// 1 4 5
// 4 5 4
// 5 6 4
// 6 3 3
// 5 2 3
// 6 7
// 1 2 5
// 2 3 3
// 1 4 5
// 4 5 4
// 5 6 4
// 6 3 3
// 5 2 3