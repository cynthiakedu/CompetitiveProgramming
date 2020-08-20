#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, D;
int ans[1005][1005];
int temp[1005];
int ct = 0;

void solve(int idx) {
    if (idx == D + 1) {
        ct++;
        for (int i = 1; i <= D; i++) {
            ans[i][ct] = temp[i];
        }
        return;
    }

    for (int i = 1; i <= K; i++) {
        if (ct >= N) return;
        temp[idx] = i;
        solve(idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> D;
    solve(1);

    if (ct < N) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= D; i++) {
            for (int j = 1; j <= N; j++) {
                cout << ans[i][j] << (j == N ? "\n" : " ");
            }
        }
    }

    return 0;
}
