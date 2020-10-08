#include <bits/stdc++.h>
using namespace std;
int N, M, arr[105] = {}, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        int u = y - 1, d = arr[x] - y;
        arr[x] = 0;
        if (x > 1) arr[x - 1] += u;
        if (x < N) arr[x + 1] += d;
    }
    for (int i = 1; i <= N; i++) cout << arr[i] << endl;

    return 0;
}
