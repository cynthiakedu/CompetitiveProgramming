#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
int N, arr[100005];

void solve() {
    if (N % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= N / 2; i++) {
        int j = N / 2 + i;
        // cout << "i " << i << " " << arr[i] << " " << arr[j] << endl;
        if (arr[i] == -1 && arr[j] == -1) {
            arr[i] = 1;
            arr[j] = 1;
        } else if (arr[i] == -1) {
            arr[i] = arr[j];
        } else if (arr[j] == -1) {
            arr[j] = arr[i];
        } else if (arr[i] != arr[j]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) cout << arr[i] << (i == N ? "\n" : " ");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        solve();
    }

    return 0;
}

// 4
// 4
// 1 1 1 1
// 4
// 1 1 1 2
// 4
// 1 -1 -1 4
// 4
// 1 -1 2 -1

// 1
// 4
// 1 -1 -1 4