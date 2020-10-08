#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, L, R;
ll arr[2][100005];
ll cum[2][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[0][i];
        arr[1][i] = arr[0][i];
    }
    sort(arr[1] + 1, arr[1] + N + 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            cum[i][j] = cum[i][j - 1] + arr[i][j];
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int type;
        cin >> type >> L >> R;
        cout << (cum[type - 1][R] - cum[type - 1][L - 1]) << endl;
    }

    return 0;
}
