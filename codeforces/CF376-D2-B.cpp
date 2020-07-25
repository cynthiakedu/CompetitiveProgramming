#include <bits/stdc++.h>
using namespace std;
int N, M;
int inAmt[105], outAmt[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        inAmt[b] += c;
        outAmt[a] += c;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += max(0, inAmt[i] - outAmt[i]);
    }
    cout << ans << endl;

    return 0;
}
