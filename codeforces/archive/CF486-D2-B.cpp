#include <bits/stdc++.h>
using namespace std;
int M, N;
int arr[105][105], b[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            arr[i][j] = -1;
        }
    }

    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> b[i][j];
            if (b[i][j] == 0) {
                for (int a = 1; a <= N; a++) arr[i][a] = 0;
                for (int b = 1; b <= M; b++) arr[b][j] = 0;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 1;
            }
        }
    }
    bool can = true;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            bool ok = false;
            if (b[i][j] == 1) {
                for (int a = 1; a <= N; a++)
                    if (arr[i][a] == 1) ok = true;
                for (int b = 1; b <= M; b++)
                    if (arr[b][j] == 1) ok = true;
                if (!ok) can = false;
            }
        }
    }
    if (!can) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                cout << arr[i][j] << (j == N ? "\n" : " ");
            }
        }
    }

    return 0;
}
