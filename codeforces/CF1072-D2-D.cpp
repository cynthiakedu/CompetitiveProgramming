#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2000;
int N, K;
char arr[mxN + 5][mxN + 5];
int mxA[mxN + 5][mxN + 5];
string a[mxN + 5][mxN + 5];
string small[mxN + 5][mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            mxA[i][j] = max(mxA[i - 1][j], mxA[i][j - 1]) + (arr[i][j] == 'a' ? 1 : 0);
        }
    }
    int ans1 = 0;
    string ans2 = "";
    bool fd = false;
    for (int k = 2 * N; k >= 2; k--) {
        for (int i = 1; i <= N; i++) {
            int j = k - i;
            if (j < 1 || j > N) continue;
            bool ok = false;
            if (i < N) {
                small[i][j] = string(1, arr[i + 1][j]) + small[i + 1][j];
                ok = true;
            }
            if (j < N) {
                string x = string(1, arr[i][j + 1]) + small[i][j + 1];
                if (!ok)
                    small[i][j] = x;
                else
                    small[i][j] = min(small[i][j], x);
            }

            int total = i + j - 1;
            if (mxA[i][j] + K >= total) {
                if (total > ans1) {
                    fd = true;
                    ans1 = total;
                    ans2 = small[i][j];
                } else if (total == ans1) {
                    if (small[i][j] < ans2) {  //MISSED
                        ans2 = small[i][j];
                    }
                }
            }
        }
        if (k < 2 * N) {
            for (int i = 1; i <= N; i++) {
                int j = k + 1 - i;
                if (j < 1 || j > N) continue;
                // cout << "clear " << i << " " << j << endl;
                small[i][j] = "";
            }
        }
    }

    if (!fd) {
        cout << (string(1, arr[1][1]) + small[1][1]) << endl;
        return 0;
    }
    for (int i = 0; i < ans1; i++) cout << 'a';
    cout << ans2 << endl;

    return 0;
}
