#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, M, arr[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    while (N % 2 == 0) {
        bool ok = true;
        for (int i = 0; i < N / 2; i++) {
            bool tf = true;
            for (int j = 0; j < M; j++) {
                if (arr[i][j] != arr[N - 1 - i][j]) tf = false;
            }
            if (!tf) {
                ok = false;
                break;
            }
        }
        if (ok) {
            N /= 2;
        } else {
            break;
        }
    }
    cout << N << endl;

    return 0;
}
