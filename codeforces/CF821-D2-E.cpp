#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
ll N, K;
ll h[105], l[105], res[105][20];

vector<vector<ll>> solve(ll height, ll width) {
    vector<vector<ll>> v[4];
    for (int j = 0; j < 4; j++) {
        v[j].resize(height + 1);
        for (int i = 0; i < height + 1; i++) v[j][i].resize(height + 1);
    }

    if (width == 0) {
        for (int i = 0; i <= height; i++) {
            v[0][i][i] = 1;
        }
        return v[0];
    }
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= height; j++) {
            v[0][i][j] = (abs(i - j) <= 1 ? 1 : 0);
        }
    }
    if (width == 1) return v[0];
    v[1] = solve(height, width / 2);

    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= height; j++) {
            for (int k = 0; k <= height; k++) {
                v[2][i][j] = (v[2][i][j] + (v[1][i][k] * v[1][k][j]) % MOD) % MOD;
            }
        }
    }

    if (width % 2 == 0) return v[2];

    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= height; j++) {
            for (int k = 0; k <= height; k++) {
                v[3][i][j] = (v[3][i][j] + (v[2][i][k] * v[0][k][j]) % MOD) % MOD;
            }
        }
    }
    return v[3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        h[i] = c;
        if (i == N) b = K;
        l[i] = b - a;
    }
    res[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        vector<vector<ll>> v = solve(h[i], l[i]);
        for (int j = 0; j <= h[i]; j++) {
            for (int k = 0; k <= min(h[i - 1], h[i]); k++) {
                res[i][j] = (res[i][j] + (res[i - 1][k] * v[k][j]) % MOD) % MOD;
            }
        }
    }
    cout << res[N][0] % MOD << endl;

    return 0;
}
