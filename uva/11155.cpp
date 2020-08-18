#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, A, B, C, M, N;
map<int, ll> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B >> C >> M >> N;
        m.clear();
        m[0] = 1;
        int cur = A;
        int cum = A % M;
        ll ans = m[cum];

        m[cum]++;
        for (int i = 2; i <= N; i++) {
            cur = (cur * B + C) % M + 1;
            cum = (cum + cur) % M;
            ans += m[cum];
            m[cum]++;
        }
        cout << "Case " << t + 1 << ": " << ans << endl;
    }

    return 0;
}
