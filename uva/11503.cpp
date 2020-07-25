#include <bits/stdc++.h>
using namespace std;
int T, F;

int p[200005], r[200005], amt[200005];
int findSet(int x) { return p[x] == x ? x : p[x] = findSet(p[x]); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (r[x] > r[y]) {
        p[y] = x;
        amt[x] += amt[y];
    } else {
        p[x] = y;
        amt[y] += amt[x];
        if (r[x] == r[y]) {
            r[y]++;
        }
    }
}
map<string, int> m;
int ct = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        m.clear();
        ct = 0;
        for (int i = 1; i < 200005; i++) {
            p[i] = i, r[i] = 0, amt[i] = 1;
        }

        cin >> F;
        for (int i = 0; i < F; i++) {
            string a, b;
            cin >> a >> b;
            if (m.count(a) == 0) {
                ct++;
                m[a] = ct;
            }
            if (m.count(b) == 0) {
                ct++;
                m[b] = ct;
            }
            int x = m[a], y = m[b];
            if (!isSameSet(x, y)) {
                unionSet(x, y);
            }
            cout << amt[findSet(x)] << endl;
        }
    }

    return 0;
}
