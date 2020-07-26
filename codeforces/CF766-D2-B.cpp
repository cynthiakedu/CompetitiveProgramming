#include <bits/stdc++.h>
using namespace std;
int N, arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N - 2; i++) {
        if (arr[i] + arr[i + 1] > arr[i + 2]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
