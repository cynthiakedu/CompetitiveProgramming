#include <bits/stdc++.h>
using namespace std;
int N, K;
char arr[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    if (K > (N * N + 1) / 2) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 'S';
        }
    }
    for (int i = 0; i < N; i++) {
        if (K == 0) break;
        for (int j = i % 2; j < N; j += 2) {
            if (K == 0) break;
            arr[i][j] = 'L';
            K--;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
