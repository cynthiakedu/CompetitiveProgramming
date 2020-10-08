#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
string A, B;

ll ct = 0;
set<int> al[25];
bool vis[25];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    ct++;
    for (auto y : al[x]) {
        dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 25; i++) al[i].clear();
        memset(vis, false, sizeof vis);

        bool ok = true;
        cin >> N;
        cin >> A >> B;
        for (int i = 0; i < N; i++) {
            if (B[i] < A[i]) {
                ok = false;
            } else if (B[i] > A[i]) {
                al[A[i] - 'a'].insert(B[i] - 'a');
                al[B[i] - 'a'].insert(A[i] - 'a');
            }
        }
        if (!ok) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;
        for (int i = 0; i < 20; i++) {
            if (vis[i]) continue;
            ct = 0;
            dfs(i);
            ans += ct - 1;
        }
        cout << ans << endl;
    }

    return 0;
}
