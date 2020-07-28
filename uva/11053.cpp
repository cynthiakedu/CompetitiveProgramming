#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        cin >> a >> b;
        map<ll, int> m;
        int idx = 0;
        m[0] = 0;
        ll lst = 0;
        while (true) {
            idx++;
            ll nxt = ((((a * lst) % N) * lst) % N + b) % N;
            if (m.count(nxt) > 0) {
                cout << N - (idx - m[nxt]) << endl;
                break;
            }
            m[nxt] = idx;
            lst = nxt;
        }
    }

    return 0;
}
