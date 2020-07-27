#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, K, ops[100005][3], queries[100005][2];
ll O[100005], C[100005];
ll ans[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> ans[i];
    for (int i = 1; i <= M; i++) cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    for (int i = 1; i <= K; i++) {
        ll l, r;
        cin >> l >> r;
        C[l]++, C[r + 1]--;
    }
    for (int i = 1; i <= M; i++) {
        C[i] = C[i - 1] + C[i];
    }
    for (int i = 1; i <= M; i++) {
        ll l = ops[i][0], r = ops[i][1], d = ops[i][2];
        O[l] += C[i] * d;
        O[r + 1] -= C[i] * d;
    }
    for (int i = 1; i <= N; i++) {
        O[i] = O[i - 1] + O[i];
        ans[i] += O[i];
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
