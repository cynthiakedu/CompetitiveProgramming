#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[3][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 3; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    if (arr[1][0] == arr[0][0] && arr[2][0] == arr[0][0]) {
        cout << 1 << endl;
        return 0;
    }
    if (arr[1][1] == arr[0][1] && arr[2][1] == arr[0][1]) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            for (int k = 0; k <= 1; k++) {
                if (arr[i][k] == arr[j][k]) {
                    // cout << "i j k " << i << " " << j << " " << k << endl;
                    if (arr[3 - (i + j)][1 - k] >= max(arr[i][1 - k], arr[j][1 - k]) || arr[3 - (i + j)][1 - k] <= min(arr[i][1 - k], arr[j][1 - k])) {
                        cout << 2 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 3 << endl;
    return 0;
}
