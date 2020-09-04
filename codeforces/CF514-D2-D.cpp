#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, M;
ll K;

ll memo[7][20][mxN + 5];
ll arr[7][mxN + 5];
ll tempans2[7];
ll ans2[7];

ll getMax(int type, int l, int r) {
    int k = log2(r - l + 1);
    return max(memo[type][k][l], memo[type][k][r - (1 << k) + 1]);
}

bool can(int l, int r) {
    ll s = 0;
    for (int i = 1; i <= M; i++) {
        int tmp = getMax(i, l, r);
        tempans2[i] = tmp;
        s += tmp;
    }
    return s <= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[j][i];
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= log2(N); j++) {
            if (j == 0) {
                for (int k = 1; k <= N; k++) {
                    memo[i][j][k] = arr[i][k];
                }
                continue;
            }
            for (int k = 1; k <= N; k++) {
                int r = k + (1 << j) - 1;
                if (r > N) continue;
                memo[i][j][k] = max(memo[i][j - 1][k], memo[i][j - 1][r - (1 << (j - 1)) + 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int l = i, r = N;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (can(i, m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (can(i, l)) {
            if (l - i + 1 > ans) {
                ans = l - i + 1;
                for (int i = 1; i <= M; i++) {
                    ans2[i] = tempans2[i];
                }
            }
        }
    }
    // cout << ans << endl;
    for (int i = 1; i <= M; i++) cout << ans2[i] << (i == M ? "\n" : " ");

    return 0;
}
