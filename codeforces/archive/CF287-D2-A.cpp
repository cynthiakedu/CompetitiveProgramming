#include <bits/stdc++.h>
using namespace std;

char arr[5][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int ct = 0;
            ct += (arr[i][j] == '#') + (arr[i + 1][j] == '#');
            ct += (arr[i][j + 1] == '#') + (arr[i + 1][j + 1] == '#');
            if (ct != 2) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
