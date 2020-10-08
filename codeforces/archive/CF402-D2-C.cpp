#include <bits/stdc++.h>
using namespace std;
int T, N, P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> P;
        int need = 2 * N + P - 2 * (N - 2);
        for (int i = 3; i <= N; i++) {
            cout << 1 << " " << i << endl;
            cout << 2 << " " << i << endl;
        }
        for (int i = 3; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (need > 0) {
                    need--;
                    cout << i << " " << j << endl;
                }
            }
        }
        if (need > 0) {
            cout << 1 << " " << 2 << endl;
        }
    }

    return 0;
}
