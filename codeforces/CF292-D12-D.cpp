#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K, E[10005][2];

int p[2][1005][505];
int ra[2][1005][505];

int findSet(int (&p1)[505], int x) {
    return (p1[x] == x ? x : p1[x] = findSet(p1, p1[x]));
}
void unionSet(int (&p1)[505], int (&r1)[505], int i, int j) {
    int x = findSet(p1, i), y = findSet(p1, j);
    if (x != y) {
        if (r1[x] < r1[y]) {
            p1[x] = y;
        } else {
            p1[y] = x;
            if (r1[x] == r1[y]) {
                r1[y]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> E[i][0] >> E[i][1];

    for (int i = 1; i <= N; i++) {
        p[0][0][i] = i;
        p[1][M + 1][i] = i;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            p[0][i][j] = p[0][i - 1][j];
            ra[0][i][j] = ra[0][i - 1][j];
        }
        unionSet(p[0][i], ra[0][i], E[i][0], E[i][1]);
        for (int j = 1; j <= N; j++) {
            findSet(p[0][i], j);
        }
    }
    for (int i = M; i >= 1; i--) {
        for (int j = 1; j <= N; j++) {
            p[1][i][j] = p[1][i + 1][j];
            ra[1][i][j] = ra[1][i + 1][j];
        }
        unionSet(p[1][i], ra[1][i], E[i][0], E[i][1]);
        for (int j = 1; j <= N; j++) {
            findSet(p[1][i], j);
        }
    }
    cin >> K;
    for (int t = 0, a, b; t < K; t++) {
        cin >> a >> b;
        vector<int> m[505];
        int p1[505] = {}, r1[505] = {};
        bool isP[505] = {};
        for (int i = 1; i <= N; i++) {
            m[p[0][a - 1][i]].push_back(i);
            p1[i] = p[1][b + 1][i];
            r1[i] = ra[1][b + 1][i];
        }
        for (int i = 1; i <= N; i++) {
            vector<int> num = m[i];
            if (num.size() == 0) continue;
            for (int i = 1; i < (int)num.size(); i++) {
                unionSet(p1, r1, num[0], num[i]);
            }
        }
        for (int i = 1; i <= N; i++) {
            findSet(p1, i);
            isP[p1[i]] = true;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (isP[i]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
