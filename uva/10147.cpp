#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int T, N, M, arr[755][2];
vector<pair<int, ii>> E;

int p[755], r[755];
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
        for (int i = 1; i < 755; i++) {
            p[i] = i;
            r[i] = 0;
        }
        E.clear();

        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int dx = abs(arr[i][0] - arr[j][0]);
                int dy = abs(arr[i][1] - arr[j][1]);
                E.push_back({dx * dx + dy * dy, ii(i, j)});
            }
        }
        cin >> M;
        for (int i = 0, u, v; i < M; i++) {
            cin >> u >> v;
            unionSet(u, v);
        }
        sort(E.begin(), E.end());
        int ct = 0;
        for (int i = 0; i < E.size(); i++) {
            int a = E[i].second.first, b = E[i].second.second;
            if (!isSameSet(a, b)) {
                ct++;
                cout << a << " " << b << endl;
                unionSet(a, b);
            }
        }
        if (ct == 0) cout << "No new highways need" << endl;
        if (t != T - 1) {
            cout << endl;
        }
    }

    return 0;
}
