#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, C, x, arr[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(arr, -1, sizeof arr);
    cin >> N >> M >> C;
    while (true) {
        cin >> x;
        if (x <= C / 2) {
            for (int i = 1; i <= N; i++) {
                if (arr[i] == -1 || x < arr[i]) {
                    arr[i] = x;
                    cout << i << endl;
                    break;
                }
            }
        } else {
            for (int i = N; i >= 1; i--) {
                if (arr[i] == -1 || x > arr[i]) {
                    arr[i] = x;
                    cout << i << endl;
                    break;
                }
            }
        }
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (arr[i] == -1) ok = false;
        }
        if (!ok) continue;
        for (int i = 2; i <= N; i++) {
            if (arr[i] < arr[i - 1]) ok = false;
        }
        if (!ok) continue;
        return 0;
    }

    return 0;
}
