#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int board[105][105];
int cum[105][105];
int p, b, s, r1, r2, c1, c2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p;
    for (int t = 0; t < p; t++) {
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                board[i][j] = 1;
            }
        }
        memset(cum, 0, sizeof cum);
        cin >> s >> b;
        for (int i = 0; i < b; i++) {
            cin >> r1 >> c1 >> r2 >> c2;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    board[r][c] = 0;
                }
            }
        }
        for (int i = 1; i <= s; i++) {
            for (int j = 1; j <= s; j++) {
                // cout << "cum " << cum[i][j] << endl;
                cum[i][j] = board[i][j] + cum[i][j - 1];
            }
        }
        int mx = 0;
        for (int i = 1; i <= s; i++) {
            for (int j = i; j <= s; j++) {
                int ct = 0, tempmx = 0;
                for (int r = 1; r <= s; r++) {
                    if (cum[r][j] - cum[r][i - 1] == j - i + 1) {
                        ct++;
                    } else {
                        ct = 0;
                    }
                    tempmx = max(tempmx, ct);
                }
                mx = max(mx, tempmx * (j - i + 1));
            }
        }
        cout << mx << endl;
    }

    return 0;
}
