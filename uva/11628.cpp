#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, M, arr[35][10005], s[35], ans[10005][2];

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N >> M;
        if (!N && !M) return 0;

        for (int i = 1; i <= N; i++) {
            ans[i][0] = 0;
            ans[i][1] = 1;
        }
        for (int i = 0; i < 35; i++) s[i] = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> arr[j][i];
                s[j] += arr[j][i];
            }
        }
        for (int i = M; i >= 1; i--) {
            if (s[i] != 0) {
                for (int j = 1; j <= N; j++) {
                    if (arr[i][j] > 0) {
                        ans[j][0] = arr[i][j];
                        ans[j][1] = s[i];
                    }
                }
                break;
            }
        }
        for (int i = 1; i <= N; i++) {
            int g = gcd(ans[i][0], ans[i][1]);
            cout << ans[i][0] / g << " / " << ans[i][1] / g << endl;
        }
    }

    return 0;
}
