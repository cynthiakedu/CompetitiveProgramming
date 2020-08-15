#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll arr[305][305];
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> M;
    for (int i = 0, u, v, c; i < M; i++) {
        ll arr2[305][305] = {};
        cin >> u >> v >> c;
        for (int a = 1; a <= N; a++) {
            for (int b = a + 1; b <= N; b++) {
                ll d1 = arr[a][u] + c + arr[v][b];
                ll d2 = arr[a][v] + c + arr[u][b];
                arr2[a][b] = arr2[b][a] = min({arr[a][b], d1, d2});
            }
        }
        ll s = 0;
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                arr[a][b] = arr2[a][b];
                if (a < b) s += arr[a][b];
            }
        }
        cout << s << endl;
    }

    return 0;
}
