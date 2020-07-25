#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int T, N, M, arr[10005][3];
int p[105], r[105];
int findSet(int x) { return p[x] == x ? x : p[x] = findSet(p[x]); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (r[x] > r[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (r[x] == r[y]) {
            r[y]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 105; i++) {
            p[i] = i;
            r[i] = 0;
        }
        cin >> N >> M;
        vector<int> added;
        vector<ii> E;
        for (int i = 1; i <= M; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            E.push_back({arr[i][2], i});
        }
        int cost1 = 0;
        sort(E.begin(), E.end());
        for (int i = 0; i < E.size(); i++) {
            int a = arr[E[i].second][0], b = arr[E[i].second][1];
            if (!isSameSet(a, b)) {
                added.push_back(E[i].second);
                cost1 += E[i].first;
                unionSet(a, b);
            }
        }
        int cost2 = INT_MAX;
        for (auto x : added) {
            for (int i = 0; i < 105; i++) {
                p[i] = i;
                r[i] = 0;
            }
            int tmpcst = 0;
            for (int i = 0; i < E.size(); i++) {
                if (E[i].second == x) continue;
                int a = arr[E[i].second][0], b = arr[E[i].second][1];
                if (!isSameSet(a, b)) {
                    tmpcst += E[i].first;
                    unionSet(a, b);
                }
            }
            bool ok = true;
            for (int i = 2; i <= N; i++) {
                if (!isSameSet(1, i)) ok = false;
            }
            if (ok) {
                cost2 = min(cost2, tmpcst);
            }
        }
        cout << cost1 << " " << cost2 << endl;
    }

    return 0;
}

// 1
// 5 8
// 1 3 75
// 3 4 51
// 2 4 19
// 3 2 95
// 2 5 42
// 5 4 31
// 1 2 9
// 3 5 66