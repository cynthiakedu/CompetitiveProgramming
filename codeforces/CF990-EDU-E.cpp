#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 1e6;
ll N, M, K, cost[mxN + 5], arr[mxN + 5], v[mxN + 5];
ll ans = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1, x; i <= M; i++) {
        cin >> x;
        arr[x] = 1;
    }
    for (int i = 1; i <= K; i++) cin >> cost[i];

    v[0] = -1;
    for (int i = 1; i <= N; i++) {
        v[i] = v[i - 1];
        if (arr[i - 1] == 0) v[i] = i - 1;
        if (debug) cout << "v " << i << " " << v[i] << endl;
    }

    for (int i = 1; i <= K; i++) {
        if (debug) cout << "START " << i << endl;
        int idx = 1, num = 0;
        bool ok = true;

        while (idx <= N) {
            int s = v[idx];
            if (debug) cout << "idx s " << idx << " " << s << endl;
            if (s < 0 || s < idx - i) {
                ok = false;
                break;
            }
            num++;
            idx = s + i + 1;
        }
        if (ok) ans = min(ans, num * cost[i]);
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    return 0;
}
