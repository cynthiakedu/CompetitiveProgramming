#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[1005][3][2], m[3][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        for (int i = 0, l; i < N; i++) {
            cin >> arr[i][0][0] >> arr[i][1][0] >> arr[i][2][0] >> l;
            for (int j = 0; j < 3; j++) {
                arr[i][j][1] = arr[i][j][0] + l;
            }
        }
        for (int i = 0; i < 3; i++) {
            m[i][0] = INT_MIN;
            m[i][1] = INT_MAX;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                m[j][0] = max(m[j][0], arr[i][j][0]);
                m[j][1] = min(m[j][1], arr[i][j][1]);
            }
        }
        ll ans = 1;
        for (int i = 0; i < 3; i++) {
            ans *= max(0, m[i][1] - m[i][0]);
        }
        cout << ans << endl;
    }

    return 0;
}
