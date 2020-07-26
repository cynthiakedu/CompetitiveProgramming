#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[3][2];
    int &r = dp[0][1];
    r = max(r, 3);
    cout << r << endl;
    cout << dp[0][1] << endl;
    return 0;
}
