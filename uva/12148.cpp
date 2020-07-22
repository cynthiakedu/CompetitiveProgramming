#include <bits/stdc++.h>
using namespace std;

int N, arr[1005][5];

map<int, int> m = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 4 == 0 && y % 100 != 0) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        int ans = 0, ct = 0;
        for (int i = 0; i < N - 1; i++) {
            int d1 = arr[i][0], m1 = arr[i][1], y1 = arr[i][2], a1 = arr[i][3];
            int d2 = arr[i + 1][0], m2 = arr[i + 1][1], y2 = arr[i + 1][2], a2 = arr[i + 1][3];
            bool ok = false;
            if (y2 == y1 + 1) {
                if (d1 == 31 && m1 == 12 && d2 == 1 && m2 == 1) ok = true;
            }
            if (y2 == y1) {
                if (m2 == m1 + 1) {
                    if (d1 == (m[m1] + (m1 == 2 && isLeap(y1))) && d2 == 1) ok = true;
                }
                if (m1 == m2 && d2 == d1 + 1) ok = true;
            }
            if (ok) {
                ans += a2 - a1;
                ct++;
            }
        }
        cout << ct << " " << ans << endl;
    }

    return 0;
}
