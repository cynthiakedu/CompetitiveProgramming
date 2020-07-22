#include <bits/stdc++.h>
using namespace std;
int N, M;
long long a[5] = {}, b[5] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        a[i % 5]++;
    }
    for (int i = 1; i <= M; i++) {
        b[i % 5]++;
    }
    long long ans = 0;
    for (int i = 1; i < 5; i++) {
        ans += a[i] * b[5 - i];
    }
    ans += a[0] * b[0];
    cout << ans << endl;

    return 0;
}
