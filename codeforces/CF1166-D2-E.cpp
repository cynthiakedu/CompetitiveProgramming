#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int M, N, arr[55][10005], arr2[55][10005];

bool check(int x, int y) {
    for (int i = 1; i <= arr[y][0]; i++) {
        if (arr2[x][arr[y][i]]) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        cin >> arr[i][0];
        for (int j = 1; j <= arr[i][0]; j++) {
            cin >> arr[i][j];
            arr2[i][arr[i][j]] = 1;
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            if (!check(i, j)) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    return 0;
}
