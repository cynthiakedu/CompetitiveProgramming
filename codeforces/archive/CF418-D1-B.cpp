#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
ll B;
int m[105], b[105];
ll x[105], k[105];
ii arr[105];
int questions[105][25];
map<int, ll> dp[105];

ll solve(int state, int idx) {
    if (idx == 0) {
        return state > 0 ? LLONG_MAX : 0;
    }
    if (dp[idx].count(state) > 0) return dp[idx][state];
    dp[idx][state] = solve(state, idx - 1);
    ll c = solve(state & b[arr[idx].second], idx - 1);
    if (c < LLONG_MAX) {
        dp[idx][state] = min(dp[idx][state], c + x[arr[idx].second]);
    }
    return dp[idx][state];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> B;
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> k[i] >> m[i];
        for (int j = 0, a; j < m[i]; j++) {
            cin >> a;
            questions[i][a - 1] = 1;
        }
        int num = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (!questions[i][j]) {
                num += (1 << j);
            }
        }
        b[i] = num;

        arr[i] = {k[i], i};
    }
    sort(arr + 1, arr + N + 1);

    ll ans = LLONG_MAX;

    for (int i = 1; i <= N; i++) {
        ll res = solve((1 << M) - 1, i);
        if (res < LLONG_MAX) {
            ans = min(ans, res + k[arr[i].second] * B);
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
