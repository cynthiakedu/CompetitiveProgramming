#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, M;
int edges[mxN + 5][2];
vector<ii> E;
int ans = 0;

int p[mxN + 5], r[mxN + 5];
int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

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

    cin >> N >> M;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 1, w; i <= M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> w;
        E.push_back({w, i});
    }

    sort(E.begin(), E.end());

    int idx = 0;
    while (idx < E.size()) {
        int j = idx;
        vector<int> v;
        while (j < E.size() && E[j].first == E[idx].first) {
            v.push_back(E[j].second);
            j++;
        }
        vector<bool> canUnion(v.size(), false);
        for (int i = 0; i < v.size(); i++) {
            int id = v[i];
            int a = edges[id][0], b = edges[id][1];
            int x = findSet(a), y = findSet(b);
            if (x != y) canUnion[i] = true;
        }
        for (int i = 0; i < v.size(); i++) {
            int id = v[i];
            int a = edges[id][0], b = edges[id][1];
            int x = findSet(a), y = findSet(b);
            if (x != y) {
                unionSet(x, y);
            } else {
                if (canUnion[i]) ans++;
            }
        }
        idx = j;
    }
    cout << ans << endl;

    return 0;
}
