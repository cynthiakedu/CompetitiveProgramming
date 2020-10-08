#include <bits/stdc++.h>
using namespace std;
int N;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> S;
    string ans = "";
    for (int i = 0; i < N; i++) {
        if (i < (N / 2)) {
            ans += S[(N - 2) - 2 * i];
        } else {
            int j = i - N / 2;
            ans += S[2 * j + (N % 2 == 0 ? 1 : 0)];
        }
    }
    cout << ans << endl;

    return 0;
}
