#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, M, K, X, Y;
ll quot[205];
ll rem[205];
ll q1[205], r1[205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K >> X >> Y;
    if (N == 1) {
        ll avg = K / M;
        ll r = K % M;
        cout << avg + (r > 0 ? 1 : 0) << " " << avg << " " << avg + (Y <= r ? 1 : 0) << endl;
        return 0;
    }
    ll avg = K / (M * 2 * (N - 1));
    ll rem1 = K % (M * 2 * (N - 1));
    ll div2 = rem1 / M;
    ll rem2 = rem1 % M;
    for (int i = 1; i <= 2 * (N - 1); i++) {
        quot[i] = avg;
        if (i <= div2) quot[i]++;
    }
    rem[div2 + 1] += rem2;

    q1[1] = quot[1];
    q1[N] = quot[N];
    r1[1] = rem[1];
    r1[N] = rem[N];

    for (int i = 2; i < N; i++) {
        q1[i] += quot[i];
        q1[i] += quot[2 * N - i];
        r1[i] += rem[i];
        r1[i] += rem[2 * N - i];
    }

    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 1; i <= N; i++) {
        mn = min(mn, q1[i] + (r1[i] < M ? 0 : 1));
        mx = max(mx, q1[i] + (r1[i] > 0 ? 1 : 0));
    }
    cout << mx << " " << mn;

    ll a = q1[X] + (Y <= r1[X] ? 1 : 0);
    cout << " " << a << endl;

    return 0;
}
