#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int N;
bool dp[10005][2];
set<string> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    N = s.size();
    for (int i = N; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            if (i == N) {
                dp[i][j] = true;
                break;
            }
            int amt = j == 0 ? 2 : 3;
            if (i <= 4 || i > N - amt) {
                dp[i][j] = false;
                break;
            }

            dp[i][j] |= dp[i + amt][1 - j];
            if (s.substr(i + amt, amt) != s.substr(i, amt)) {
                dp[i][j] |= dp[i + amt][j];
            }
            if (dp[i][j]) {
                S.insert(s.substr(i, amt));
            }
        }
    }
    cout << S.size() << endl;
    for (auto x : S) cout << x << endl;

    return 0;
}
