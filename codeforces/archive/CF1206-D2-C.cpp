#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i < 2 * N; i += 2) {
        arr[i - 1] = i;
        arr[(i - 1 + N) % (2 * N)] = i + 1;
    }
    for (int i = 0; i < 2 * N; i++) {
        cout << arr[i] << (i == 2 * N - 1 ? "\n" : " ");
    }

    return 0;
}
