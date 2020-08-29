#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1000;
int T, N, M;
int D[mxN + 5], A[mxN + 5][mxN + 5], B[mxN + 5][mxN + 5];
int maxTime[mxN + 5];
bool wa[mxN + 5];

void solve() {
    memset(maxTime, 0, sizeof maxTime);
    memset(wa, false, sizeof wa);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> D[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> B[i][j];
        }
    }
    vector<ii> v;
    for (int j = 1; j <= M; j++) {
        int mxT = 0;
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (!D[i]) continue;
            mxT = max(mxT, A[i][j]);
            if (!B[i][j]) ok = false;
        }
        if (ok) {
            v.push_back({mxT, j});
        }
    }
    if (!v.size()) {
        cout << "NO" << endl;
        return;
    }
    sort(v.begin(), v.end());
    int i1 = 0;
    while (i1 < v.size()) {
        int j1 = i1;
        while (j1 < v.size() && v[j1].first == v[i1].first) {
            ii p = v[j1];
            for (int i = 1; i <= N; i++) {
                if (D[i]) continue;
                if (!B[i][p.second]) wa[i] = true;
                maxTime[i] = max(maxTime[i], A[i][p.second]);
            }
            j1++;
        }
        bool ok = true;
        int t2 = 1000000000;
        for (int i = 1; i <= N; i++) {
            if (D[i]) continue;
            if (!wa[i]) {
                t2 = min(t2, maxTime[i]);
            }
        }

        if (t2 > v[i1].first) {
            cout << "YES" << endl;
            cout << t2 - 1 << " " << j1 << endl;
            for (int j = 0; j < j1; j++) cout << v[j].second << (j == j1 - 1 ? "\n" : " ");
            return;
        }

        i1 = j1;
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}