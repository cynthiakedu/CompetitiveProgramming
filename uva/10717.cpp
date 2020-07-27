#include <bits/stdc++.h>
using namespace std;
int N, T, C[55], tables[15], ans[15][2];

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int lcm(vector<int> v) {
    int lcm = 1;
    for (auto x : v) {
        int x1 = x / gcd(lcm, x);
        lcm *= x1;
    }
    return lcm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> N) && (cin >> T)) {
        if (N == 0 && T == 0) return 0;
        for (int i = 0; i < N; i++) cin >> C[i];
        for (int i = 0; i < T; i++) cin >> tables[i];

        for (int i = 0; i < T; i++) ans[i][0] = 0, ans[i][1] = INT_MAX;

        for (int a = 0; a < N; a++) {
            for (int b = a + 1; b < N; b++) {
                for (int c = b + 1; c < N; c++) {
                    for (int d = c + 1; d < N; d++) {
                        int x = lcm({C[a], C[b], C[c], C[d]});
                        for (int t = 0; t < T; t++) {
                            int m1 = (tables[t] / x) * x;
                            ans[t][0] = max(ans[t][0], m1);
                            int m2 = ((tables[t] + x - 1) / x) * x;
                            ans[t][1] = min(ans[t][1], m2);
                        }
                    }
                }
            }
        }
        for (int t = 0; t < T; t++) cout << ans[t][0] << " " << ans[t][1] << endl;
    }

    return 0;
}
