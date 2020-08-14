#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int nchoose3[105];
int K;
int ans[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 3; i <= 100; i++) {
        nchoose3[i] = (i * (i - 1) * (i - 2)) / 6;
    }

    cin >> K;
    int idx = 0;

    for (int i = 100; i >= 3; i--) {
        while (K >= nchoose3[i]) {
            for (int a = idx; a < idx + i; a++) {
                for (int b = idx; b < idx + i; b++) {
                    if (a == b) continue;
                    ans[a][b] = 1;
                    ans[b][a] = 1;
                }
            }
            K -= nchoose3[i];
            idx += i;
        }
    }
    cout << idx << endl;
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
