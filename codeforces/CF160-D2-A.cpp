#include <bits/stdc++.h>
using namespace std;
int N, arr[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int s = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr + 1, arr + N + 1);
    int cum = 0;
    for (int i = N; i >= 1; i--) {
        cum += arr[i];
        s -= arr[i];
        if (cum > s) {
            cout << N - i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
