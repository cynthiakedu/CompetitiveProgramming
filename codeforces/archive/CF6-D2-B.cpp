#include <bits/stdc++.h>
using namespace std;
int N, M;
char c;
char arr[105][105];
int mnx = INT_MAX, mxx = INT_MIN, mny = INT_MAX, mxy = INT_MIN;
set<char> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == c) {
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool ok = false;
            if (i == mnx - 1 && mny <= j && j <= mxy) ok = true;
            if (i == mxx + 1 && mny <= j && j <= mxy) ok = true;
            if (j == mny - 1 && mnx <= i && i <= mxx) ok = true;
            if (j == mxy + 1 && mnx <= i && i <= mxx) ok = true;
            if (ok && arr[i][j] != '.') S.insert(arr[i][j]);
        }
    }
    cout << S.size() << endl;
    return 0;
}
