#include <bits/stdc++.h>
using namespace std;
int N, K, arr[205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= 2 * N + 1; i++) {
        cin >> arr[i];
    }
    for (int i = 2; i <= 2 * N; i++) {
        if (arr[i] - 1 > arr[i - 1] && arr[i] - 1 > arr[i + 1]) {
            arr[i] -= 1;
            K--;
        }
        if (K == 0) {
            break;
        }
    }
    for (int i = 1; i <= 2 * N + 1; i++) {
        cout << arr[i] << (i == 2 * N + 1 ? "\n" : " ");
    }

    return 0;
}
