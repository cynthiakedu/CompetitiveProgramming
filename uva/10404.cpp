#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e6;
int N, M;
set<int> S;
bool dp[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N) {
        S.clear();
        memset(dp, false, sizeof dp);
        cin >> M;
        for (int i = 0, x; i < M; i++) {
            cin >> x;
            S.insert(x);
        }
        dp[0] = false;
        for (int i = 1; i <= N; i++) {
            for (auto x : S) {
                if (i >= x) {
                    dp[i] |= !dp[i - x];
                }
            }
        }
        cout << (dp[N] ? "Stan" : "Ollie") << " wins" << endl;
    }

    return 0;
}
