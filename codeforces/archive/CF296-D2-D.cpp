#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll adj[505][505];
ll ans[505][505];
int add[505];
set<int> S;
vector<ll> ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
            ans[i][j] = LLONG_MAX;
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> add[i];
    }

    for (int k = N; k >= 1; k--) {
        int k1 = add[k];
        for (auto x : S) {
            ans[k1][x] = adj[k1][x];
            ans[x][k1] = adj[x][k1];
        }
        for (auto x : S) {
            for (auto y : S) {
                if (x == y) continue;
                if (ans[k1][x] != LLONG_MAX && ans[x][y] != LLONG_MAX) {
                    ans[k1][y] = min(ans[k1][y], ans[k1][x] + ans[x][y]);
                }
                if (ans[y][x] != LLONG_MAX && ans[x][k1] != LLONG_MAX) {
                    ans[y][k1] = min(ans[y][k1], ans[y][x] + ans[x][k1]);
                }
            }
        }
        for (auto i : S) {
            for (auto j : S) {
                if (i == j) continue;
                if (ans[i][k1] != LLONG_MAX && ans[k1][j] != LLONG_MAX) {
                    ans[i][j] = min(ans[i][j], ans[i][k1] + ans[k1][j]);
                }
            }
        }

        ll ans1 = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (ans[i][j] == LLONG_MAX) continue;
                ans1 += ans[i][j];
            }
        }
        ans2.push_back(ans1);
        S.insert(k1);
    }
    for (int i = ans2.size() - 1; i >= 0; i--) cout << ans2[i] << (i == 0 ? "\n" : " ");

    return 0;
}
