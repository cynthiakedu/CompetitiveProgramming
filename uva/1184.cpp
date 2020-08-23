#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, M;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L;
    cin >> L;
    for (int l = 0; l < L; l++) {
        cin >> N >> M;

        for (int i = 1, u, v; i <= M; i++) {
            cin >> u >> v;
            m[v]++;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (m[i] == 0) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
