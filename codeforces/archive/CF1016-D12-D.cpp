#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, a[105], b[105], arr[105][105];
int ans[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int A = 0, B = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        A ^= a[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
        B ^= b[i];
    }
    if (A != B) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i <= 30; i++) {
        for (int x = 1; x <= N - 1; x++) {
            for (int y = 1; y <= M - 1; y++) {
                arr[x][y] = 0;
            }
        }
        for (int x = 1; x <= N - 1; x++) {
            int temp = 0;
            for (int y = 1; y <= M - 1; y++) {
                temp ^= arr[x][y];
            }
            arr[x][M] = ((a[x] >> i) & 1) ^ temp;
        }
        int r = 0;
        for (int y = 1; y <= M - 1; y++) {
            int temp = 0;
            for (int x = 1; x <= N - 1; x++) {
                temp ^= arr[x][y];
            }
            arr[N][y] = ((b[y] >> i) & 1) ^ temp;
            r ^= arr[N][y];
        }
        arr[N][M] = ((a[N] >> i) & 1) ^ r;

        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= M; y++) {
                ans[x][y] += arr[x][y] * (1 << i);
            }
        }
    }
    cout << "YES" << endl;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            cout << ans[x][y] << (y == M ? "\n" : " ");
        }
    }
    return 0;
}
