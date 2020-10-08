#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int d = N / K;
    int rem = N % K;
    string ans = "";
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < K; j++) {
            ans += (char)('a' + j);
        }
    }
    for (int j = 0; j < rem; j++) {
        ans += (char)('a' + j);
    }
    cout << ans << endl;

    return 0;
}
