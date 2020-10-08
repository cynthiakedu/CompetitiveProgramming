#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
int arr[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    if (M < N - 1 || M > 2 * (N + 1)) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= N - 1; i++) arr[i] = 1;
    M -= (N - 1);
    for (int i = 0; i <= N; i++) {
        int need = min(2 - arr[i], M);
        M -= need;
        arr[i] += need;
        if (M == 0) break;
    }
    for (int i = 0; i < arr[0]; i++) cout << "1";
    for (int i = 1; i <= N; i++) {
        cout << "0";
        for (int j = 1; j <= arr[i]; j++) cout << "1";
    }
    cout << endl;

    return 0;
}
