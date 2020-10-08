#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
const int mxN = 1e6;
int N, L, M;

ll cost[mxN + 5], arr1[105], arr2[105], arr12[105];
ll arr[105];

vector<ll> solve(int x) {
    vector<ll> v1(M, 0);
    if (x == 0) {
        v1[0] = 1;
        return v1;
    }
    if (x == 1) {
        for (int i = 0; i < M; i++) v1[i] = arr[i] % MOD;
        return v1;
    }
    vector<ll> v2 = solve(x / 2);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int k = (i + j) % M;
            v1[k] = (v1[k] + (v2[i] * v2[j]) % MOD) % MOD;
        }
    }
    if (x % 2 == 0) return v1;
    vector<ll> v3(M, 0);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int k = (i + j) % M;
            v3[k] = (v3[k] + (v1[i] * arr[j]) % MOD) % MOD;
        }
    }
    return v3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> M;

    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        arr1[x % M] = (arr1[x % M] + 1) % MOD;
    }
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        arr[cost[i] % M] = (arr[cost[i] % M] + 1) % MOD;
    }
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        x = -x - cost[i] + 3 * M;
        arr2[x % M] = (arr2[x % M] + 1) % MOD;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int k = (i - j + 3 * M) % M;
            arr12[k] = (arr12[k] + (arr2[i] * arr1[j]) % MOD) % MOD;
        }
    }
    vector<ll> v = solve(L - 2);

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ans = (ans + (v[i] * arr12[i]) % MOD) % MOD;
    }
    cout << ans << endl;

    return 0;
}

// 2 9 13
// 4 6
// 2 1
// 3 4