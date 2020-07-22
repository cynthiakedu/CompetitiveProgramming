#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int X, a, b;
    cin >> N;
    cin >> X;
    bool ok = true;
    int pos = 7 - X;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 2; i <= N; i++) {
        int v[7] = {};
        a = arr[i][0], b = arr[i][1];
        v[a] = 1;
        v[b] = 1;
        v[7 - a] = 1;
        v[7 - b] = 1;
        if (v[pos] == 1) {
            ok = false;
            break;
        } else {
            for (int j = 1; j <= 6; j++) {
                if (v[j] == 0 && j != pos) {
                    pos = j;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
