#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int T, N, M;
map<string, int> m;  //RESET
int ct = 0;          //RESET

int p[2005], r[2005];  //RESET
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
        for (int i = 0; i < 2005; i++) {
            p[i] = i, r[i] = 0;
        }
        ct = 0;
        m.clear();
        cin >> M >> N;
        vector<pair<int, ii>> E;
        for (int i = 0; i < N; i++) {
            string x, y;
            int cst = 0;
            cin >> x >> y >> cst;
            if (m.count(x) == 0) {
                ct++;
                m[x] = ct;
            }
            if (m.count(y) == 0) {
                ct++;
                m[y] = ct;
            }
            int a = m[x], b = m[y];
            E.push_back(pair<int, ii>{cst, ii(a, b)});
        }
        sort(E.begin(), E.end());
        int mstcost = 0;
        for (int i = 0; i < E.size(); i++) {
            int c = E[i].first, x = E[i].second.first, y = E[i].second.second;
            if (!isSameSet(x, y)) {
                mstcost += c;
                unionSet(x, y);
            }
        }
        cout << mstcost << endl;
        if (t != T - 1) {
            cout << endl;
        }
    }

    return 0;
}
